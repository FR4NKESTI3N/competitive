#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int n, m;
int s, f;
string eff = "{";
string names;
unordered_map<int, vector<int>> edges;

void calc(int city, string cur){
    // cout << city + 1<< '\n';
    cur += names[city%n];
    if(city == f){
        // cout << cur << '\n';
        if(cur < eff)
            eff = cur;
        return;
    }
    if(edges[city%n].size() == 0)
        return;
    for(int i = 0; i < edges[city%n].size(); ++i){
        calc(edges[city%n][i] %n, cur);
    }
}

int main(){
    cin >> n >> m;
    cin >> names;
    for(int i = 0; i < n; ++i)
        edges[i];
    int tmp1, tmp2;
    for(int i = 0; i < m; ++i){
        cin >> tmp1 >> tmp2;
        --tmp1; --tmp2;
        edges[tmp1%n].push_back(tmp2);
    }
    cin >> s >> f;
    --s; --f;
    calc(s%n, string(""));
    if(eff == "{")
        cout << "No way\n";
    else
        cout << eff << '\n';
    return 0;
}
