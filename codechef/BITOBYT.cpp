#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        n -= 1;
        long long p = pow((long long)2, (n) / 26);
        n %= 26;
        if(n >= 10)
            cout << "0 0 " << p << '\n';
        else if(n >= 2)
            cout << "0 " << p << " 0 \n";
        else
            cout << p << " 0 0\n";
    }
    return 0;
}
