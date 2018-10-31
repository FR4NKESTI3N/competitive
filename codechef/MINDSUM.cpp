#include <iostream>

using namespace std;

typedef long long ll;

int digitalRoot(ll x){
    return static_cast<int>(1 + ((x - 1) % 9));
}

int digitalRoot128(__int128_t x){
    return static_cast<int>(1 + ((x - 1) % 9));
}

ll getSteps(__int128_t x, ll steps = 0){
    if(x < 10){
        return steps;
    }
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return getSteps(sum, steps + 1);
}

int main(){
    int t;
    ll n, d;
    cin >> t;
    while(t--){
        cin >> n >> d;
        int N = digitalRoot(n), D = digitalRoot(d);
        int min_fac = 0, min_val = 100, temp;
        __int128_t x;
        int old_steps = 100;
        for(int k = 0; k < 10; ++k){
            temp = digitalRoot(N + (k * D));
            x = d;
            x *= k;
            x += n;
            if(temp < min_val){
                min_val = temp;
                min_fac = k;
                old_steps = min_fac + getSteps(x);
            }
            else if(temp == min_val){
                if(old_steps > k + getSteps(x)){
                    min_fac = k;
                    old_steps = k + getSteps(x);
                }
            }
        }
        x = d;
        x *= min_fac;
        x += n;
        cout << digitalRoot128(x) << ' ' << old_steps << '\n';
    }
    return 0;
}
