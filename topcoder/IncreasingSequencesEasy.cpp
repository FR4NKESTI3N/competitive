#include <iostream>


#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

const long long MOD = 998244353;

class IncreasingSequencesEasy{
public:
    int count(std::vector<int> l, std::vector<int> r){
        int cnt = 0;
        //int minl = *min_element(l.begin(), l.end());
        int maxr = *max_element(r.begin(), r.end());
        int memo[l.size()+1][maxr + 1];
        memset(memo, 0, sizeof memo);
        for(int i = l[0]; i <= r[0]; ++i)
            memo[0][i] = 1;
        for(int i = 0; i < l.size(); ++i){
            // for(int j = l[i-1]; j < l[i]; ++j){
            //     memo[i][l[i]]+=memo[i-1][j];
            //     memo[i][l[i]] %= 998244353;
            // }
            // for(int j = l[i] + 1; j <= r[i]; ++j){
            //     memo[i][j] += memo[i-1][j] + memo[i][j-1];
            //     memo[i][j] %= 998244353;
            // }
            for(int j = l[i]; j <= r[i]; ++j){
                memo[i+1][j] = memo[i][j] +  (j>0)?(memo[i][j-1]):0;
            }
        }
        // for(int j = 0; j <= (maxr+1); ++j){
        //     for(int i = 0; i <= l.size(); ++i)
        //         cout<<memo[j][i]<<' ';
        //     cout<<'\n';
        // }
        for(int i = 0; i <= maxr; i++)
            cnt += memo[l.size() - 1][i];
        return cnt;
    }
};

int main(void){
    IncreasingSequencesEasy a;
    cout<<a.count(vector<int> {1, 3, 1, 4},vector<int> {6, 5, 4, 6});
    return 0;
}
