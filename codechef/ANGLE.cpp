#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>

using namespace std;

int getAX(int ay, int az, double pq){
    return ceil(sqrt((ay * ay) + (az * az) - (2 * az * ay * pq)));
}

int main(){
    int t, n;
    cin >> t;
    double p, q;
    while(t--){
        cin >> n >> p >> q;
        vector<int> ar(n), arr;
        for(int i = 0; i < n; ++i)
            cin >> ar[i];
        map<int, int> tree;
        for(int i = 0; i < n; ++i){
            tree.insert({ar[i], i});
        }
        arr = ar;
        sort(arr.begin(), arr.end());
        double pq = p / q;
        double theta = 0;
        vector<int> res(0);
        for(int i = 0; i < n - 1; ++i){
            for(int j = i + 1; j < n; ++j){BUDDYNIM
                int temp_res = getAX(ar[i], ar[j], pq);
                if(ar[i] + ar[j] <= temp_res || ar[i] + temp_res <= ar[j] || ar[j] + temp_res <= ar[i])
                    continue;
                // cout << ar[i] << ' ' << ar[j] << ' ' << temp_res << '\n';
                auto x = (lower_bound(arr.begin(), arr.end(), temp_res));
                if(x == ar.end())
                    continue;
                double theta_temp = acos((-((*x) * (*x)) + (ar[i] * ar[i]) + (ar[j] * ar[j])) / (2 * ar[i] * ar[j]));
                // cout << "-----" << temp_res << " " << theta_temp << '\;
                // cout << (theta_temp/3.1415)*180 << "==========" << "\n";
                int z = tree[*x];
                if(theta_temp > theta && z != i && z != j){
                    theta = theta_temp;
                    res = vector<int>({i, j, z});
                }
            }
        }
        if(res.empty()){
            cout << "-1\n";
        }
        else{
            for(auto r : res)
                cout << r + 1 << ' ';
            cout << '\n';
        }
    }
    return 0;
}
