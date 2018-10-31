#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <string>

using namespace std;
typedef pair<int, int> pii;
inline int manhattanDistance(pii x, pii y){
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main(){
    int t, n, m;
    string s;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<pii> points;
        vector<int> dist(n + m + 1, 0);
        for(int i = 0; i < n; ++i){
            cin >> s;
            for(int j = 0; j < m; ++j)
                if(s[j] - '0')
                    points.push_back(pii(i, j));
        }
        int N = points.size();
        for(int i = 0; i < N; ++i){
            for(int j = i + 1; j < N; ++j){
                // cout << manhattanDistance(points[i], points[j]) << "-----------\n";
                ++dist[manhattanDistance(points[i], points[j])];
            }
        }
        for(int i = 1; i <= n + m - 2; ++i)
            cout << dist[i] << ' ';
        cout << '\n';
    }
    return 0;
}
