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
    tt.open("test.txt");
    cin >> n;
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);
    long long x;
    while(n--){
        cin >> x;
        if(x == 1){
            cout << "0\n";
            continue;
        }
        int low = 2, high = 600000000, mid;
        while(low <= high){
            mid = (low + high) >> 1;
            // cout << f(mid) << "====\n";
            if(f(mid) >= x){
                // if(f(mid) == x){
                //     tt << mid - 1 << '\n';
                //     break;
                // }
                if(f(mid - 1) < x){
                    cout << mid - 2 << '\n';
                    break;
                }
                else{
                    high = mid - 1;
                }
            }
            else
                low = mid + 1;
        }
        if(low > high)
            cout << "0\n";
    }
    return 0;
}
