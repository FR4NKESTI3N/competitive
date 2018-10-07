#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

class UnionFind{
private:
    vector<int> p, rank;
public:
    UnionFind(int N){
        rank.assign(N, 0);
        p.assign(N, 0);
        for(int i = 0; i < N; ++i)
            p[i] = i;
    }
    int findSet(int i){
        return (p[i] == i)? i : (p[i] = findSet(p[i]));
    }
    void unionSet(int i, int j){
        int x = findSet(i), y = findSet(j);
        if(x != y){
            if(rank[x] > rank[y])
                p[y] = x;
            else
                p[x] = y;
            if(rank[x] == rank[y])
                ++rank[y];
        }
    }

};

int main(){
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<int> order(n, 0);
    UnionFind forest(n);
    int tmp1, tmp2;
    for(int i = 0; i < m; ++i){
        cin >> tmp1 >> tmp2;
        --tmp1; --tmp2;
        order[tmp1]++;
        order[tmp2]++;
        forest.unionSet(tmp1, tmp2);
    }

    vi min_order(n), max_order(n);
    vector<set<int>> min_child, max_child;
    for(int i = 0; i < n; ++i)
        min_order[i] = max_order[i] = order[i];

    for(int i = 0; i < n; ++i){
        int x = forest.findSet(i);
        if(i == x)
            continue;
        if(min_order[i] < min_order[x])
            min_order[x] = min_order[i];
        if(max_order[i] > max_order[x])
            max_order[x] = max_order[i];
    }

    int count = 0;
    for(int i = 0; i < n; ++i){
        int x = forest.findSet(i);
        if(order[i] <= a * min_order[x])
            continue;
        if(order[i] >= b * max_order[x])
            continue;
        count++;
    }
    cout << count << '\n';

    return 0;
}
