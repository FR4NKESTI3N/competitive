#include <iostream>

using namespace std;

typedef long long ll;

int steps = 1000, MIN = 9;

int digitSum(ll x){
    int sum = 0;
    while(x){
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

void recursiveSolve(ll n, ll d, int step = 0){
    if(step > 11)
        return;
    if(n < MIN){
        MIN = n;
        steps = step;
    }
    else if(n == MIN && step < steps){
        steps = step;
    }
    recursiveSolve(digitSum(n), d, step + 1);
    recursiveSolve(n + d, d, step + 1);
}

int main(){
    int t;
    cin >> t;
    ll n, d;
    while(t--){
        cin >> n >> d;
        steps = 1000;
        MIN = 9;
        recursiveSolve(n, d);
        cout << MIN << ' ' << steps << '\n';

    }
    return 0;
}
