#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> a, b;
multimap<int, int> order;

ll sum(vector<int> &ar){
    ll S = 0;
    for(auto i : ar)
        S += i;
    return S;
}

ll getSum(int k){
    int index, val, n = a.size(), max_smaller;
    vector<int> c = a;
    for(auto &i : order){
        index = i.second;
        max_smaller = -1;
        for(int i = max(0, index - k); i <= min(n - 1, index + k); ++i){
            if(i == index)
                continue;
            if(c[i] <= c[index]){
                if(max_smaller == -1 || b[i] > b[max_smaller])
                    max_smaller = i;
            }
        }
        if(max_smaller == -1)
            c[index] = 1;
        if(c[max_smaller] == c[index])
            continue;
        c[index] = c[max_smaller] + 1;
    }
    // cout << "k = " << k <<'\t'<<sum(c)<<'\n';
    // for(auto x : c)
    //     cout << x << ' ';
    // cout << '\n';
    return sum(c);
}

int main(){
    int t, n, s, count;
    cin >> t;
    while(t--){
        count = 1;
        cin >> n >> s;
        a.assign(n, 0);
        b.assign(n, 0);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        map<int, int> sorted;
        for(auto i : a)
            sorted[i];
        for(auto &i : sorted)
            i.second = count++;
        for(int i = 0; i < n; ++i)
            b[i] = sorted[a[i]];
        a = b;
        ll S = sum(a);
        if(S <= s){
            cout << n + 1 << '\n';
            continue;
        }
        if(n > s){
            cout << "0\n";
            continue;
        }
        order.clear();
        for(int i = 0; i < n; ++i){
            order.insert(make_pair(b[i], i));
        }
        // for(auto i : order)
        //     cout << i.first << ' '<<i.second << '\t';
        // cout << '\n';
        int low = 1, high = n - 1, mid;
        while(high >= low){
            mid = (low + high) / 2;
            // cout << mid << "------\n";
            if(getSum(mid) <= s){
                low = mid + 1;
                continue;
            }
            else if(getSum(mid - 1) <= s){
                break;
            }
            else{
                high = mid - 1;
                continue;
            }
        }
        cout << mid << '\n';
        // for(int k = 0; k <= n; ++k)
        //     cout << getSum(k) << '\n';
    }
    return 0;
}
