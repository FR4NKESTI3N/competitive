#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n, m;
    while(t--){
        cin >> n >> m;
        vector<int> a(n), b(m);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        for(int i = 0; i < m; ++i)
            cin >> b[i];
        sort(b.begin(), b.end());
        sort(a.begin(), a.end());
        if(a == b){
            cout << "Bob\n";
        }
        else
            cout << "Alice\n";
    }
    return 0;
}
