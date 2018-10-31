#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <queue>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pii;
typedef vector<pii> vii;

ll func(vector<ll> a, vector<ll> b, ll y){
    ll sum = 0;
    int n = a.size();
    ll gap, baloons;
    for(int i = 0; i < n; ++i){
        gap = max(static_cast<ll>(0), (a[i] * b[i]) - y);
        baloons = (gap / b[i]) + ((gap % b[i]) != 0);
        sum += baloons;
    }
    return sum;
}

ll getMax(vector<ll> a, vector<ll> b, ll y){
    ll MAX = 0, val;
    int n = a.size();
    ll gap, baloons;
    for(int i = 0; i < n; ++i){
        gap = max(static_cast<ll>(0), (a[i] * b[i]) - y);
        baloons = (gap / b[i]) + ((gap % b[i]) != 0);
        MAX = max(MAX, (a[i] - baloons) * b[i]);
    }
    return MAX;
}

int main(){
    long long n, m, MAX = 0;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    for(int i = 0; i < n; ++i)
        MAX = max(MAX, a[i] * b[i]);
    ll low = 0, high = MAX, mid;
    while(low <= high){
        mid = (low + high) >> 1;
        if(mid <= 0){
            cout << "0\n";
            break;
        }
        if(func(a, b, mid) <= m){
            if(func(a, b, mid - 1) > m){
                cout << getMax(a, b, mid) << '\n';
                break;
            }
            else{
                high = mid - 1;
            }
        }
        else{
            low = mid + 1;
        }
    }

    return 0;
}
