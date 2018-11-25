#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <iterator>
#include <cassert>

using namespace std;

// Set a high value to use as infinite
const int MAX = 1000000001;

int n, m, P, source, sink;

int flow_temp = 0, flow_max = 0;
vector<int> p;

int getNum(int x, int y){
    return (x * m) + y;
}

// Karp's Ford Funkerson implementation
void augment(int v, int min_weight, vector<vector<int>> &edge){
    if(v == source){
        flow_temp = min_weight;
        return;
    }
    else if(p[v] != -1){
        augment(p[v], min(min_weight, edge[p[v]][v]), edge);
        edge[p[v]][v] -= flow_temp;
        edge[v][p[v]] -= flow_temp;
    }
}

void solve(){
    cin >> n >> m >> P;
    vector<int> mat(2 * m * n + 2, 0);
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        assert(s.size() == m);
        for(int j = 0; j < m; ++j){
            mat[getNum(i, j)] = s[j];
        }
    }
    vector<vector<int>> edge(2 * m * n + 2, vector<int> (2 * m * n + 2, -1));
    source =  2 * n * m, sink = 2 * n * m + 1;

    // Costruct graph edges
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(mat[getNum(i, j)] == '#')
                continue;
            else if(mat[getNum(i, j)] == '@')
                edge[getNum(i, j)][getNum(i, j) + n * m]
                    = edge[getNum(i, j) + n * m][getNum(i, j)] = 1;
            else if(mat[getNum(i, j)] == '.')
                edge[getNum(i, j)][getNum(i, j) + n * m]
                    = edge[getNum(i, j) + n * m][getNum(i, j)] = P;
            else if(mat[getNum(i, j)] == 'c'){
                edge[getNum(i, j)][getNum(i, j) + n * m]
                    = edge[getNum(i, j) + n * m][getNum(i, j)] = MAX;
                edge[source][getNum(i, j)] = MAX;
            }
            else{
                edge[getNum(i, j)][getNum(i, j) + n * m]
                    = edge[getNum(i, j) + n * m][getNum(i, j)] = MAX;
                edge[getNum(i, j) + n * m][sink] = MAX;
            }
        }

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j){
            if(n - i > 1){
                edge[getNum(i, j) + n * m][getNum(i + 1, j)] = MAX;
                edge[getNum(i + 1, j) + n * m][getNum(i, j)] = MAX;
            }
            else if(i > 0){
                edge[getNum(i, j) + n * m][getNum(i - 1, j)] = MAX;
                edge[getNum(i - 1, j) + n * m][getNum(i, j)] = MAX;
            }
            if(m - j > 1){
                edge[getNum(i, j) + n * m][getNum(i, j + 1)] = MAX;
                edge[getNum(i, j + 1) + n * m][getNum(i, j)] = MAX;
            }
            else if(j > 0){
                edge[getNum(i, j) + n * m][getNum(i, j - 1)] = MAX;
                edge[getNum(i, j - 1) + n * m][getNum(i, j)] = MAX;
            }
        }

    //bfs till all paths are exausted
    while(true){
        flow_temp = 0;
        vector<int> visited(2 * n * m + 2, 0);
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        p.assign(2 * n * m + 2, -1);

        while(q.empty() != true){
            int u = q.front();
            q.pop();
            for(int v = 0; v < 2 * n * m + 2; ++v){
                if(edge[u][v] > 0 && visited[v] != 1){
                    visited[v] = 1;
                    q.push(v);
                    p[v] = u;
                }
            }
        }
        augment(sink, MAX, edge);
        if(flow_temp == 0)
            break;
        flow_max += flow_temp;
    }
    cout << min(1000000000, flow_max) << '\n';
}

int main(){
    int t;
    cin >> t;

    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    while(t--){
        flow_max = 0;
        flow_temp = 0;
        solve();
    }
    return 0;
}
