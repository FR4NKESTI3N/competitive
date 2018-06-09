#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<vector<string>> v(100);
    int x; string s;
    cin >> n;
    for(int i = 0; i < n/2; ++i){
        cin >> x >> s;
        v[x].push_back("-");
    }
    for(int i = 0; i < n/2; ++i){
        cin >> x >> s;
        v[x].push_back(s);
    }
    for(auto i : v){
        for(auto j : i)
            cout << j << ' ';
    }
    cout<<'\n';
    return 0;
}
