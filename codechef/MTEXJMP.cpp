#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

int main(){
    int n, bud;
    cin >> n;
    vector<int> cost(n);
    for(int i = 0; i < n; ++i)
        cin >> cost[i];
    cin >> bud;
    sort(cost.begin(), cost.end());
    int sum = accumulate(cost.begin(), cost.end(), 0);
    vector<vector<int>> dp(5000, vector<int>(n, 0));
    unordered_map<int, int> dp1, dp2;
    dp1.emplace(0, 0);
    dp2 = dp1;
    for(int i = 0; i < n; ++i){
        for(auto x : dp1){
            int k = 0;
            auto it = dp1.find(x.first + cost[i]);
            if(it != dp1.end()){
                k = it->second;
            }
            dp2[cost[i] + x.first] = max(k, dp1[x.first] + 1);
        }
        dp1 = dp2;
    }
    if(bud <= 0){
        cout << "0\n";
        return 0;
    }
    auto it = dp1.find(bud);
    if(it == dp1.end())
        cout << "-1\n";
    else
        cout << dp1[bud] << '\n';
    return 0;
}
