#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

long long f(long long x){
    return (1 + (x * x - x) * 3);
}

int main(){
    int n;
    ofstream tt;
    ifstream ttt;

    tt.open("testt.txt");
    ttt.open("input11.txt");

    ttt >> n;
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
    long long x;
    while(n--){
        cout << n << '\n';
        cin >> x;
        if(x == 1){
            tt << "0\n";
            continue;
        }
        int low = 2, high = 600000000, mid;
        while(f(low) < x){
            // cout << f(low) << ' ';
            ++low;
        }
        tt << low - 2 << '\n';
    }
    return 0;
}
