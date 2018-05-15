#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        vector<int> a(n + 2);
        a[0] = INT_MAX, a[n + 1] = INT_MAX;
        for(int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        vector<int> id;
        for(int i = 1; i <= n; ++i){
            if(a[i] < a[i - 1] && a[i] < a[i + 1])
                id.push_back(i);
        }
        n = id.size();
        vector<vector<long long>> dp(n,vector<long long> (3, 0));
        if(n)
            dp[0][0] = a[id[0]];
        else{
            for(int i = 1; i < a.size() - 1; ++ i)
                printf("%d ", a[i]);
            printf("\n");
            continue;
        }
        for(int i = 1; i < n; ++i){
            if(id[i] - id[i - 1] != 2 || a[id[i] - 1] - a[id[i]] - a[id[i - 1]] > 0)
                dp[i][2] = 1;
            dp[i][0] = dp[i - 1][1] + a[id[i]];
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        }
        // for(auto x : id)
        //     cout<<a[x]<<' ';
        // cout<<'\n';
        // for(auto x : dp)
        //     cout<<x[0]<<' ';
        // cout<<'\n';
        // for(auto x : dp)
        //     cout<<x[1]<<' ';
        // cout<<'\n';
        int k = 1;
        for(int i = n - 1; i > 0; --i){
            if(k){
                if(dp[i][2])
                    a[id[i]] *= -1;
                else if(dp[i][0] >= dp[i][1]){
                    k = 0;
                    a[id[i]] *= -1;
                }
            }
            else
                k = 1;
        }
        if(k)
            a[id[0]] *= -1;
        for(int i = 1; i < a.size() - 1; ++i)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
