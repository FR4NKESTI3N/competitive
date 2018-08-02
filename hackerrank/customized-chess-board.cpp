#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> mat[i][j];
            }
        }
        int flag = 1;
        for(int i = 0; i < n && flag; ++i){
            for(int j = 0; j < n - 1 && flag; ++j){
                if(mat[i][j] == mat[i][j + 1])
                    flag = 0;
            }
        }
        for(int i = 0; i < n - 1 && flag; ++i){
            for(int j = 0; j < n && flag; ++j){
                if(mat[i][j] == mat[i + 1][j])
                    flag = 0;
            }
        }
        cout << (flag ? "Yes\n" : "No\n");
    }
    return 0;
}
