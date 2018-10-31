#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
inline int manhattanDistance(pii x, pii y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

inline pii remap(pii p, int n, int m){
    int d = max(m, n);
    return pii(p.first + p.second, n - p.first + p.second);
}

inline int subMatrixSum(vector<vector<int>> &mat, pii i, pii j){
    i.first = max(0, i.first);
    i.second = max(0, i.second);
    j.first = min((int)mat.size() - 1, j.first);
    j.second = min((int)mat.size() - 1, j.second);
    int sum;
    sum = mat[j.first][j.second];
    if(i.first > 0)
        sum -= mat[i.first - 1][j.second];
    if(i.second > 0)
        sum -= mat[j.first][i.second - 1];
    if(i.first > 0 && i.second > 0)
        sum += mat[i.first - 1][i.second - 1];
    return sum;
}

int main(){
    int t, n, m;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pii> points;
        vector<int> dist(n + m + 1, 0);
        vector<vector<int>> mat_mod(2 * max(m, n), vector<int>(2 * max(m, n), 0));
        for(int i = 0; i < n; ++i){
            cin >> s;
            for(int j = 0; j < m; ++j)
                if(s[j] - '0')
                    points.push_back(pii(i, j));
        }
        int N = points.size();
        pii temp;
        for(int i = 0; i < N; ++i){
            temp = remap(points[i], n, m);
            mat_mod[temp.first][temp.second] = 1;
        }

        vector<vector<int>> mat = mat_mod;
        for(int i = 1; i < mat_mod.size(); ++i){
            mat_mod[0][i] += mat_mod[0][i - 1];
            mat_mod[i][0] += mat_mod[i - 1][0];
        }
        for(int i = 1; i < mat_mod.size(); ++i){
            for(int j = 0; j < mat_mod.size(); ++j){
                mat_mod[i][j] += mat_mod[i - 1][j] + mat_mod[i][j - 1] - mat_mod[i - 1][j - 1];
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                temp = remap(pii(i, j), n, m);
                for(int k = 1; k <= n + m - 2; ++k){
                    if(mat[temp.first][temp.second] == 0)
                        continue;
                    dist[k] += subMatrixSum(mat_mod, pii(temp.first - k, temp.second - k), pii(temp.first + k, temp.second + k)) - 1;
                }
            }
        }
        for(int i = 1; i <= m + n - 2; ++i)
            cout << (dist[i] - dist[i - 1]) / 2 << ' ';
        cout << '\n';
    }
    return 0;
}
