#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    vector<long long> S(1000002, 0);
    for(int i = 2; i < 1000002; ++i){
        if(!S[i]){
            int k = i;
            while(k < 1000002){
                S[k] += i;
                k += i;
            }
        }
    }
    cout << '\n';
    int t, n, temp;
    cin >> t;
    while(t--){
        int maxi = 0;
        long long pairs = 0;
        cin >> n;
        vector<long long> a(1000002, 0);
        for(int i = 0; i < n; ++i){
            cin >> temp;
            maxi = max(temp, maxi);
            a[temp]++;
        }
        for(int i = 2; i <= a.size(); ++i){
            if(!a[i])
                continue;
            pairs += a[i] * (a[i] - 1);
            int k = 2 * i;
            while(k <= a.size()){
                if(a[k]){
                    if(S[k] % S[i] == 0){
                        pairs += a[i] * a[k];
                    }
                }
                k += i;
            }
        }
        cout << pairs <<'\n';
    }
}
