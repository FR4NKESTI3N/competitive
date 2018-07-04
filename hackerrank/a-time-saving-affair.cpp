#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <climits>
#include <functional>

using namespace std;

vector<int> dist;

bool red(int k, int t){
    return (t/k) & 1;
}

struct compare{
    bool operator()(const int &l, const int &r){
        return dist[l] < dist[r];
    }
};

int main(){
    int n, k, m, a, b, c;
    cin>>n>>k>>m;
    vector<vector<int>> graph(n, vector<int> (n, INT_MAX));
    vector<vector<int>> edges(n);
    for(int i = 0; i < m; ++i){
        cin>>a>>b>>c;
        a--; b--;
        graph[a][b] = graph[b][a] = c;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vector<int> dist(n, INT_MAX);
    vector<bool> visited(n, false);
    dist[0] = 0;
    set<pair<int, int>> Q;
    Q.insert(make_pair(0, 0));
    while(!Q.empty()){
        pair<int, int> p = *Q.begin();
        Q.erase(Q.begin());
        int cost = 0, u = p.second;
        if(red(k, dist[u]))
            cost = k - (dist[u] % k);
        for(auto v : edges[u]){
            if(dist[v] > dist[u] + graph[u][v] + cost){
                dist[v] = dist[u] + graph[u][v] + cost;
                Q.insert(make_pair(dist[v], v));
            }
        }
    }
    cout<<dist[n - 1]<<'\n';
    return 0;
}
