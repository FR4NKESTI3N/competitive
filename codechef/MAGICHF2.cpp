#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
typedef long long ll;

double calc(ll n, ll k){
    if(n == 1)
        return 1;
    else if(n == 2){
        if(!k)
            return (double)0.5;
        else
            return 1;
    }
    else if(n == 3 || n == 4){
        if(k == 1)
            return (double)0.5;
        else if(k >= 2)
            return 1;
    }
    if(!k)
        return ((double)1) / n;
    ll nn = n / 2;

    return calc(n - nn, k - 1);
}

int main(){
    int t;
    cin >> t;
    ll n, k;
    while(t--){
        cin >> n >> k;
        ll t1, t2;
        if(n == 2){
            cout << "0.5\n";
            continue;
        }
        if(n == 1)
            cout << setprecision(8) << 1.0 << '\n';
        else if(n == 3 || n == 4){
            if(k == 1)
                cout << setprecision(8) << 0.5 << '\n';
            else if(k >= 2)
                cout << setprecision(8) << 1.0 << '\n';
            else if(k == 0)
                cout << setprecision(8) << fixed << ((double)1) / n << '\n';
        }
        else if(k == 0)
            cout << setprecision(8) << fixed << ((double)1) / n << '\n';
        else{
            ll nn = (n / 2) + ((n / 2) % 2);
            cout << setprecision(8) << fixed << calc(max(nn, n - nn), k - 1) << '\n';
        }

    }
    return 0;
}
