#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <bitset>
#include <stdexcept>
int masks[1024];
long long dp[1<<10];

using namespace std;

int main(void){
    int n;
    cin>>n;
    string s;
    unsigned long long pairs = 0;
    memset(masks, 0, sizeof masks);
    memset(dp, 0, sizeof dp);
    while(n--){
        cin>>s;
        int x = 0;
        for(auto a : s){
            x |= 1 << (a - '0');
        }
        masks[x]++;
    }
    for(int i = 0; i < 1<<10; ++i)
        dp[i] = masks[i];
    for(int bit = 0; bit < 10; ++bit){
        for(int mask = (1<<10) - 1; mask >=0; --mask){
            if(!(mask & (1<<bit))){
                dp[mask]+=dp[mask^(1<<bit)];
            }
        }
    }
    for(int i = 1; i < (1<<10)-1; ++i)
        pairs += masks[i]*dp[((1<<10)-1)-i];
    pairs+=masks[(1<<10) - 1]*(dp[0]-1);
    cout<<pairs/2<<'\n';
    return 0;
}
