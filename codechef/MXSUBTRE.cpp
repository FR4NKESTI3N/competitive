#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

struct _Tree {
    int value;
    struct _Tree *left;
    struct _Tree *right;
};

typedef struct _Tree Tree;
// you may add more methods here

pii maxTreeWeight(Tree *root) {
    if(root == NULL)
        return pii(0, 0);
    pii sum_left = maxTreeWeight(root->left);
    pii sum_right = maxTreeWeight(root->right);
    pii sum = {(sum_left.second + sum_right.second + root->value), 0};
    sum.second = max(sum_left.first, sum_left.second) + max(sum_right.first, sum_right.second);
    return sum;
}

int maxTreeWeight(int nodes, Tree *root) {
    //add code to this function to solve the problem
    //don't write code in this editor
    //your code will not be saved across submissions
    pii sum = maxTreeWeight(root);
    return max(sum.first, sum.second);
}

Tree* tearDownTree(Tree *root) {
    if(root != NULL) {
        free(root->left);
        free(root->right);
        free(root);
    }
    return NULL;
}

Tree* insertInTree(Tree *root, int value) {
    if(root == NULL) {
        root = (Tree *)malloc(sizeof(Tree));
        root->value = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if(value <= root->value) {
        root->left = insertInTree(root->left, value);
        return root;
    }
    root->right = insertInTree(root->right, value);
    return root;
}

int main() {
    int i;
    int T, N;
    int p;
    Tree *root = NULL;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&N);
        for(i=0;i<N;i++) {
            scanf("%d",&p);
            root = insertInTree(root, p);
        }
        printf("%d\n",maxTreeWeight(N,root));
        root = tearDownTree(root);
    }
    return 0;
}
