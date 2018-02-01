#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n, m, k;
    cin>>n>>m>>k;
    long long ways = 0;
    vector<string> mat(n);
    for(int i = 0; i < n; ++i)
        cin>>mat[i];
    for(int i = 0; i < n; ++i){
        long long c = 0;
        for(int j = 0; j < m; ++j){
            if(mat[i][j] == '.')
                ++c;
            else{
                ways+=max(c-k+1, (long long)0);
                c = 0;
            }
        }
        ways+=max(c-k+1, (long long)0);
    }
    if(k == 1){
        cout<<ways<<'\n';
        return 0;
    }
    for(int i = 0; i < m; ++i){
        long long c = 0;
        for(int j = 0; j < n; ++j){
            if(mat[j][i] == '.')
                ++c;
            else{
                ways+=max(c-k + 1, (long long)0);
                c = 0;
            }
        }
        ways+=max(c-k+1, (long long)0);
    }
    cout<<ways<<'\n';
    return 0;
}
