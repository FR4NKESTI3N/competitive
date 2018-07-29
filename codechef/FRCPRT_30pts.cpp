#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int t, n, m;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int> (m, 0));
        for(int i = 0; i < n; ++i){
            cin >> s;
            for(int j = 0; j < m; ++j)
                mat[i][j] = s[j] - '0';
        }
        cin >> s;
        for(int i = 0; i < s.length(); ++i){
            // cout<<"\n\n";
            // for(int i = 0; i < n; ++i){
            //     for(int j = 0; j < m; ++j){
            //         cout << mat[i][j];
            //     }
            //     cout<<'\n';
            // }
            if(i < s.length() - 1 && (s[i + 1] == s[i] || (s[i] == 'L' && s[i + 1] == 'R') || (s[i] == 'R' && s[i + 1] == 'L')
                || (s[i] == 'U' && s[i + 1] == 'D') || (s[i] == 'D' && s[i + 1] == 'U')))
                continue;
            if(s[i] == 'L'){
                for(int j = 0; j < n; ++j){
                    int x = 0;
                    for(int k = 0; k < m; ++k){
                        if(mat[j][k] == 1){
                            mat[j][k] = 0;
                            mat[j][x++] = 1;
                        }
                    }
                }
            }
            else if(s[i] == 'R'){
                for(int j = 0; j < n; ++j){
                    int x = m - 1;
                    for(int k = m - 1; k >= 0; --k){
                        if(mat[j][k] == 1){
                            mat[j][k] = 0;
                            mat[j][x--] = 1;
                        }
                    }
                }
            }
            else if(s[i] == 'U'){
                for(int j = 0; j < m; ++j){
                    int y = 0;
                    for(int k = 0; k < n; ++k){
                        if(mat[k][j] == 1){
                            mat[k][j] = 0;
                            mat[y++][j] = 1;
                        }
                    }
                }
            }
            else if(s[i] == 'D'){
                for(int j = 0; j < m; ++j){
                    int y = n - 1;
                    for(int k = n - 1; k >= 0; --k){
                        if(mat[k][j] == 1){
                            mat[k][j] = 0;
                            mat[y--][j] = 1;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << mat[i][j];
            }
            cout<<'\n';
        }
    }
    return 0;
}
