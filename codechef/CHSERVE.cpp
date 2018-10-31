#include <iostream>

using namespace std;

int main(){
    int t, p1, p2, k, K, flag;
    cin >> t;
    while(t--){
        cin >> p1 >> p2 >> k;
        K = 2 * k;
        flag = (p1 + p2) % K;
        cout << (flag < K/2 ? "CHEF\n" : "COOK\n");
    }
    return 0;
}
