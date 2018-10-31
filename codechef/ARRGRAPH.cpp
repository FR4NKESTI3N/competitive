#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> vi;

class DisjointSet{
public:
    vi rank, p;

    DisjointSet(int n){
        rank.assign(n, 0);
        p.assign(n, 0);
        for(int i = 0; i < n; ++i)
            p[i] = i;
    }

    int getParent(int x){
        return (p[x] == x) ? x : p[x] = getParent(p[x]);
    }

    void unionSet(int i, int j){
        int x = getParent(i), y = getParent(j);
        if(x == y)
            return;
        if(rank[x] > rank[y])
            p[y] = x;
        else
            p[x] = y;
        if(rank[x] == rank[y])
            ++rank[y];
    }
};

int gcd(int a, int b){
    int temp;
    while(b){
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        int flag = 0;
        DisjointSet forest(n);
        for(int i = 0; i < n - 1 && flag == 0; ++i){
            for(int j = i + 1; j < n && flag == 0; ++j){
                if(gcd(a[i], a[j]) == 1)
                    forest.unionSet(i, j);
                // cout << a[i] << ' ' << a[j] << '\t' << gcd(a[i], a[j]) << '\n';
            }
        }
        int par = forest.getParent(0);
        for(int i = 1; i < n; ++i){
            if(forest.getParent(i) != par){
                flag = 1;
                break;
            }
        }
        vector<int> c(51, 0);
        for(auto i : a)
            ++c[i];
        if(flag){
            cout << "1\n";
            if(c[43] == 0)
                cout << "43 ";
            else
                cout << "47 ";
            for(int i = 1; i < n; ++i)
                cout << a[i] << ' ';
            cout << '\n';
        }
        else{
            cout << "0\n";
            for(auto i : a)
                cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}
