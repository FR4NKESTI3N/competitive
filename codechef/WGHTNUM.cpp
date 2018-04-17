#include <iostream>

const long long MOD = 1000000007;

using namespace std;

long long ipowMOD(long long base, unsigned long long exp){
    long long result = 1;
    while(exp){
        if(exp & 1)
            result = (result * base)%MOD;
            exp = exp>>1;
            base = (base * base)%MOD;
    }
    return result;
}

int main(){
    long long t, n ,w;
    cin>>t;
    while(t--){
        cin>>n>>w;
        if(w >= 9 || w <= -10){
            cout<<"0\n";
            continue;
        }
        long long ways;
        if(w >= 0)
            ways = 9 - w;
        else
            ways = 10 + w;
        ways *= ipowMOD(10, n - 2);
        cout<<ways%MOD<<'\n';
    }
    return 0;
}
