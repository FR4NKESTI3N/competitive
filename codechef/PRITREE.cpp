#include <iostream>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

class UnionFind{
private:
    vector<int> p, rank;
public:
    UnionFind(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)
            p[i] = i;
    }

    int findSet(int i){
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    void unionSet(int i, int j){
        if(findSet(i) != findSet(j)){
            int x = findSet(i), y = findSet(j);
            if(rank[x] > rank[y])
                p[y] = x;
            else{
                p[x] = y;
                if(rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }
};

int main(){
    bool prime[90010];
    for(int i = 0; i <= 90000; ++i){
        prime[i] = 1;
    }
    prime[2] = 1;
    for(int i = 2; i <= 300; ++i){
        if(prime[i]){
            for(int j = i * 2; j <= 90001; j += i)
                prime[j] = 0;
        }
    }
    int n;
    cin >> n;
    vector<int> V(n);
    UnionFind disjoint(n);
    for(int i = 0; i < n; ++i)
        cin >> V[i];
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(prime[V[i] + V[j]]){
                if(disjoint.findSet(i) != disjoint.findSet(j)){
                    cout << i + 1 << ' ' << j + 1 << '\n';
                    disjoint.unionSet(j, i);
                }
            }
        }
    }
    for(int i = 0; i < n - 2; ++i){
        for(int j = i + 1; j < n - 1; ++j){
            for(int k = j + 1; k < n; ++k){
                if(prime[V[i] + V[j] + V[k]]){
                    if(disjoint.findSet(i) != disjoint.findSet(j)){
                        cout << i + 1 << ' ' << j + 1 << '\n';
                        disjoint.unionSet(j, i);
                    }
                    if(disjoint.findSet(k) != disjoint.findSet(i)){
                        cout << k + 1 << ' ' << i + 1 << '\n';
                        disjoint.unionSet(k, i);
                    }
                }
            }
        }
    }
    for(int i = 0; i < n - 3; ++i){
        for(int j = i + 1; j < n - 2; ++j){
            for(int k = j + 1; k < n - 1; ++k){
                for(int l = k + 1; k < n; ++k){
                    if(prime[V[i] + V[j] + V[k]] + V[l]){
                        if(disjoint.findSet(i) != disjoint.findSet(j)){
                            cout << i + 1 << ' ' << j + 1 << '\n';
                            disjoint.unionSet(j, i);
                        }
                        if(disjoint.findSet(k) != disjoint.findSet(i)){
                            cout << k + 1 << ' ' << i + 1 << '\n';
                            disjoint.unionSet(k, i);
                        }
                        if(disjoint.findSet(l) != disjoint.findSet(i)){
                            cout << l + 1 << ' ' << i + 1 << '\n';
                            disjoint.unionSet(l, i);
                        }
                    }
                }
            }
        }
    }
    set<int> s;
    for(int i = 0; i < n; ++i){
        s.insert(disjoint.findSet(i));
    }
    int x = *s.begin();
    s.erase(s.begin());
    for(auto y : s){
        cout << x + 1 << ' ' << y + 1 << '\n';
        x = y;
    }
    return 0;
}
