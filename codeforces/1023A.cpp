#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    if(m + 1 < n){
        cout << "NO\n";
        return 0;
    }
    int idx = 0;
    for(; idx < n && s[idx] != '*'; ++idx);
    if(idx == n && m != n){
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i < idx; ++i){
        // cout << t[i] << ' ';
        if(s[i]!= t[i]){
            cout << "NO\n";
            return 0;
        }
    }
    int j = m - 1;
    for(int i = n - 1; i >idx; --i){
        if(s[i] != t[j]){
            cout << "NO\n";
            return 0;
        }
        --j;
    }
    cout << "YES\n";
    return 0;
}
