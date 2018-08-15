#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long ipow(long long base, long long exp, long long mod){
    if(mod == 0)
        mod = MOD;
    long long result = 1;
    base %= mod;
    if(base == 1)
        return 1;
    while(exp){
        if(exp & 1)
            result = static_cast<long long>((static_cast<__int128>(result) * static_cast<__int128>(base)) % static_cast<__int128>(mod));
        exp >>= 1;
        base = static_cast<long long>((static_cast<__int128>(base) * static_cast<__int128>(base)) % static_cast<__int128>(mod));
    }
    return result;
}

long long gcd(long long a, long long b){
    if(!a)
        return b;
    if(!b)
        return a;
    long long t;
    while(b){
        t = b;
        b = a%b;
        a = t;
    }
    return a;
}

int main(){
    int t;
    long long a, b, n, tmp;
    cin >> t;
    while(t--){
        cin >> a >> b >> n;
        tmp = ipow(a, n, a - b) + ipow(b, n, a - b);
        cout << gcd(tmp, a - b) << '\n';
    }
    return 0;
}
