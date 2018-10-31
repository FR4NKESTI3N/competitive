#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

inline int subMatrixSum(vector<vector<int>> &mat, int i, int j, int k){
    int sum = mat[i + k][j + k];
    if(i > 0)
        sum -= mat[i - 1][j + k];
    if(j > 0)
        sum -= mat[i + k][j - 1];
    if(i > 0 && j > 0)
        sum += mat[i - 1][j - 1];
    return sum;
}

int main(){
    int n, m, q;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        for(int j = 0; j < m; ++j)
            mat[i][j] = s[j] - '0';
    }
    cin >> q;
    vector<int> queries(q);
    for(int i = 0; i < q; ++i)
        cin >> queries[i];
    vector<vector<int>> case1(n, vector<int>(m)), case2(n, vector<int>(m));
    int cur = 0;
    for(int i = 0; i < m; ++i){
        case1[0][i] = cur;
        cur ^= 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j)
            case1[i][j] = case1[i - 1][j] ^ 1;
    }
    cur = 1;
    for(int i = 0; i < m; ++i){
        case2[0][i] = cur;
        cur ^= 1;
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j)
            case2[i][j] = case2[i - 1][j] ^ 1;
    }

    // generate xor matrix
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            case1[i][j] ^= mat[i][j];
            case2[i][j] ^= mat[i][j];
        }

    // sum matrix
    for(int i = 1; i < n; ++i){
        case1[i][0] += case1[i - 1][0];
        case2[i][0] += case2[i - 1][0];
    }
    for(int j = 1; j < m; ++j){
        case1[0][j] += case1[0][j - 1];
        case2[0][j] += case2[0][j - 1];
    }

    for(int i = 1; i < n; ++i){
        for(int j = 1; j < m; ++j){
            case1[i][j] += case1[i - 1][j] + case1[i][j - 1] - case1[i - 1][j - 1];
            case2[i][j] += case2[i - 1][j] + case2[i][j - 1] - case2[i - 1][j - 1];
        }
    }

    int max_sum = 0, max_size = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            for(int k = 1; (i + k < n) && (j + k < m); ++k){
                int sum1 = subMatrixSum(case1, i, j, k);
                int sum2 = subMatrixSum(case2, i, j, k);
                hash[sum1] = max(hash[sum1], k + 1);
                hash[sum2] = max(hash[sum2], k + 1);
            }
        }
    }

    for(int i = 1; i <= 40001; ++i){
        hash[i] = max(hash[i], hash[i - 1]);
    }

    for(int i = 0; i < q; ++i){
        cout << hash[min(40000, queries[i])] << '\n';
    }
    return 0;
}
