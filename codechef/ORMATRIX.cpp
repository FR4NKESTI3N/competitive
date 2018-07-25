#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
typedef vector<int> vi;

int sum(vi x){
    int r = 0;
    for(auto a : x)
        r += a;
    return r;
}

int main(){
    int t, n, m;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vi> mat(n, vi(m, 0));
        vi r(n, 0), c(m, 0);
        int ss = 0;
        for(int i = 0; i < n; ++i){
            cin >> s;
            for(int j = 0; j < m; ++j){
                mat[i][j] = s[j] - '0';
                ss += mat[i][j];
                r[i] += mat[i][j];
                c[j] += mat[i][j];
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(mat[i][j] == 1)
                    cout << 0 << ' ';
                else if(r[i] + c[j] >= 1)
                    cout << 1 << ' ';
                else if(ss >= 1)
                    cout << 2 << ' ';
                else
                    cout << -1 << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}
