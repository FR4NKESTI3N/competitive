#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<int> a(3), x(2);
        cin >> a[0] >> a[1] >> a[2] >> x[0] >> x[1];
        sort(a.begin(), a.end());
        sort(x.begin(), x.end());
        if(((a[0] + a[1] + a[2]) != x[0] + x[1]) || a[0] > x[0] || a[1] > x[1]){
            cout<<"NO\n";
            continue;
        }
        else
            cout<<"YES\n";
    }
    return 0;
}
