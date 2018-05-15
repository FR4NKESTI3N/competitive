#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

using namespace std;

void genTree(vector<int> &tree, const vector<int> &a, unordered_map<int, int> &tree_loc, int cur, int low, int high){
    if(low > high)
        return;
    int mid = (low + high)/2;
    tree[cur] = mid;
    tree_loc[a[mid]] = cur;
    genTree(tree, a, tree_loc, cur<<1, low, mid - 1);
    genTree(tree, a, tree_loc, (cur<<1) + 1, mid + 1, high);
}

int getSteps(unordered_map<int, int> tree_index, unordered_map<int, pair<int, int>> pairs, vector<int> a, vector<int> tree, int x){
    int i1 = tree_index[x];
    int i2 = i1>>1;
    int high = 0, low = 0, hsteps = 0, lsteps = 0;
    while(i2 != 0){
        //printf("\t%d, %d", a[tree[i2]], (i1 - (i2<<1)));
        if(i1 == i2<<1){
            high++;
            if(a[tree[i2]] < x)
                hsteps++;
        }
        else{
            low++;
            if(a[tree[i2]] > x)
                lsteps++;
        }
        i1 = i1>>1;
        i2 = i2>>1;
    }
    if(low > pairs[x].first || high > pairs[x].second)
        return -1;
    return max(lsteps, hsteps);
}

int main(){
    int t, n, m, temp;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        vector<int> a(n), sorted;
        unordered_map<int, int> index, tree_index;
        unordered_map<int, pair<int, int>> pairs;
        for(int i = 0; i < n; ++i){
            scanf("%d", &a[i]);
            index[a[i]] = i;
        }
        vector<int> tree(2*n, -1);
        genTree(tree, a, tree_index, 1, 0, n - 1);
        sorted = a;
        sort(sorted.begin(), sorted.end());
        for(int i = 0; i < n; ++i){
            pairs[sorted[i]] = make_pair(i, n - 1 - i);
        }
        int x;
        for(int i = 0; i < m; ++i){
            scanf("%d", &x);
            int i1 = tree_index[x];
            int i2 = i1>>1;
            int high = 0, low = 0, hsteps = 0, lsteps = 0;
            while(i2 != 0){
        //printf("\t%d, %d", a[tree[i2]], (i1 - (i2<<1)));
                if(i1 == i2<<1){
                    high++;
                    if(a[tree[i2]] < x)
                        hsteps++;
                }
                else{
                    low++;
                    if(a[tree[i2]] > x)
                        lsteps++;
                }
                i1 = i1>>1;
                i2 = i2>>1;
            }
            if(low > pairs[x].first || high > pairs[x].second)
                printf("-1\n");
            else printf("%d\n", max(hsteps, lsteps));
        }
    }
    return 0;
}
