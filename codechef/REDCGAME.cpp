#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n, k;
    while(t--){
        cin >> n >> k;
        long long sum = 0, temp;
        vector<int> ar;
        for(int i = 0; i < n; ++i){
            cin >> temp;
            if(temp > k){
                ar.push_back(temp - k);
                sum += k;
            }
            else
                sum += temp;
        }
        if(ar.size() > 0){
            sort(ar.begin(), ar.end());
            for(int i = 0; i < ar.size() - 1; ++i){
                ar[i + 1] -= ar[i];
            }
            sum += ar.back();
        }
        cout << sum << '\n';
    }
    return 0;
}
