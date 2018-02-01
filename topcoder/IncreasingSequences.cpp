#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>

class IncreasingSequences{
private:
    const long long MOD = 998244353;
public:
    int count(std::vector<int> L, std::vector<int> R){
        for(int i = 0; i < L.size(); ++i){
            L[i] %= MOD;
            R[i] %= MOD;
        }
        int maxR = *max_element(R.begin(), R.end());
        std::vector<std::vector<long long>> dp(2,std::vector<long long> (maxR, 0));
        for(int i = L[0]; i <= R[0]; ++i)
            dp[0][i] = 1;
        int i = 0;
        for(int I = 1; I < L.size(); ++I){
            i = I%2;
            fill(dp[i].begin(), dp[i].end(), 0);
            for(int k = L[I - 1]; k < L[I]; ++k){
                dp[i][L[I]] += dp[(i + 1)%2][k];
                dp[i][L[I]] %= MOD;
            }
            for(int j = L[I] + 1; j <= R[I]; ++j){
                dp[i][j] += dp[i][j - 1] + dp[(i + 1)%2][j - 1];
                dp[i][j] %= MOD;
            }
        }
        int sum = 0;
        for(int j = 0; j <= maxR; ++j){
            sum += dp[i][j];
            sum %= MOD;
        }
        return sum;
    }
};
