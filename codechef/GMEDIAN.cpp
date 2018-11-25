#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

static int MOD = 1000000007;

int main(){
    //binomial coefficient
    int C[2002][1001];
    memset(C, 0, sizeof(C));
    for(int n = 0; n <= 2000; ++n){
        for(int r = 0; r <= 1000; ++r){
            if(r == n || r == 0)
                C[n][r] = 1;
            else
                C[n][r] = (C[n - 1][r] + C[n - 1][r - 1]) % MOD;
        }
    }

    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> ar(n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &ar[i]);
        long long res = n, temp;
        sort(ar.begin(), ar.end());
        for(int i = 1; i < n - 1; ++i){
            int l = i, r = n - i - 1;
            // for(int j = 1; j <= min(l, r); ++j){
            //     temp = C[l][j];
            //     temp = (temp * C[r][j]) % MOD;
            //     res += temp;
            // }
            // res %= MOD;
            res = (res + C[l + r][min(l, r)] - 1) % MOD;
        }
        int i = 0, j;
        while(i < n - 1){
            j = i;
            while(ar[j] == ar[i])
                ++j;
            --j;
            if(i == j){
                i = j + 1;
                continue;
            }
            for(int x = i; x <= j - 1; ++x){
                for(int y = x + 1; y <= j; ++y){
                    res++;
                    int l = x, r = n - y - 1;
                    res = (res + C[l + r][min(l, r)] - 1) % MOD;
                }
            }
            i = j + 1;
        }
        cout << res % MOD << '\n';
    }

    return 0;
}
