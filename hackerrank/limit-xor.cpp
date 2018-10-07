#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

struct node{
    node* left;
    node* right;
    node* parent;
    int leaf;

    node(){
        leaf = 1;
    }
};

node* head = new node;

void init(node* temp){
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    // temp->leaf = NULL;
    temp->leaf = 1;

}

void update(node* root){
    if (root->right && root->left)
        root->leaf = root->right->leaf + root->left->leaf;
    else if (root->left)
        root->leaf = root->left->leaf;
    else if (root->right)
        root->leaf = root->right->leaf;

    if (root->parent)
        update(root->parent);
}

void insert(string num, int level, node* root){
    if (level == -1){
        update(root);
        return;
    }

    int x = num[level] - '0';
    if (x == 1){
        if (!root->right){
            node* temp = new node;
            init(temp);
            root->right = temp;
            temp->parent = root;
        }
        insert(num, level - 1, root->right);
    }
    else{
        if (!root->left){
            node* temp = new node;
            init(temp);
            root->left = temp;
            temp->parent = root;
        }
        insert(num, level - 1, root->left);
    }
}

void solver(string num, string k, int level, node* root, long long &ans)
{
    if (level == -1)
        return;
    if (num[level] == '1'){
        if (k[level] == '1'){
            if (root->right)
                ans += root->right->leaf;
            if (root->left)
                solver(num, k, level - 1, root->left, ans);
        }
        else if (root->right)
                solver(num, k, level - 1, root->right, ans);
    }
    else if (k[level] == '0' && root->left)
                solver(num, k, level - 1, root->left, ans);
    else{
            if (root->left)
                ans += root->left->leaf;
            if (root->right)
                solver(num, k, level - 1, root->right, ans);
    }
}

long long solve(vector<int> a, int n, int K)
{
    int max_element = K;
    for (int i = 0; i < n; i++)
        max_element = max(max_element, a[i]);
    int height = (int)ceil(1.0 * log2(max_element)) + 1;
    string k = "";

    int temp = K;

    for (int j = 0; j < height; j++){
        k = k + char(temp % 2 + '0');
        temp /= 2;
    }

    string init = "";
    for (int i = 0; i < height; i++)
        init += '0';

    insert(init, height - 1, head);

    long long ans = 0;
    temp = 0;
    for (int i = 0; i < n; i++){
        string s = "";
        temp = (temp ^ a[i]);

        for (int j = 0; j < height; j++)
        {
            s = s + char(temp % 2 + '0');
            temp = temp >> 1;
        }

        solver(s, k, height - 1, head, ans);
        insert(s, height - 1, head);
    }

    return ans;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> ar(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> ar[i];
    // vector<int> xor_prefix(n);
    // xor_prefix[0] = ar[0];

    cout << solve(ar, n, k) << '\n';
    return 0;
}
