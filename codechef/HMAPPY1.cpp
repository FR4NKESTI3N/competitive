#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <deque>
#include <set>
#include <iterator>

using namespace std;
typedef pair<int, int> pii;

struct compare{
    bool operator()(const pii &a, const pii &b){
        return (a.second - a.first) > (b.second - b.first);
    }
};

int main(){
    int n, Q, k;
    cin >> n >> Q >> k;
    vector<int> a(n), ar;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ar = a;
    ar.insert(ar.end(), a.begin(), a.end());
    ar.push_back(0);
    deque<pii> que;
    multiset<pii, compare> tree;
    string q;
    cin >> q;

    int i = 0, j;
    while(ar[i] != 1 && i < 2 * n)
        ++i;
    j = i;
    while(i < 2 * n && j <= 2 * n){
        if(ar[j] == 1){
            ++j;
        }
        else{
            tree.insert(pii(i, j - 1));
            i = j + 1;
            while(ar[i] != 1 && i < 2 * n)
                ++i;
            j = i;
        }
    }

    int t = 0;
    for(auto c : q){
        if(c == '!'){
            t = (t + 1) % n;
        }
        else{
            int maxx = 0;
            for(auto x : tree){
                if(x.first > (2 * n) - 1 - t || x.second < n - t)
                    continue;
                if(x.second - x.first + 1 <= maxx)
                    break;
                int l = max(x.first, n - t), r = min((2 * n) - 1 - t, x.second);
                maxx = max(maxx, r - l + 1);
                if(maxx >= k)
                    break;
            }
            cout << min(k, maxx) << '\n';
        }
    }
    return 0;
}
