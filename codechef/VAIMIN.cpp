//brute force solution
#include <iostream>
#include <vector>
#include <set>
#include <utility>

using namespace std;
set<pair<int, int>> Set;

int steps = 0;

void recursive(int i, int j, int p, int q, int c){
    if(i > p || j > q){
        return;
    }
    if(Set.find(make_pair(i, j)) != Set.end()){
        return;
    }
    if(i + j == p + q){
        steps++;
        return;
    }
    recursive(i + 1, j, p, q, c);
    if(i - j > c)
        recursive(i, j + 1, p, q, c);

}

int main(){
    int p, q, c, m, tmp1, tmp2;
    cin >> p >> q >> c >> m;
    while(m--){
        cin >> tmp1 >> tmp2;
    	if(tmp1 > p || tmp2 > q)
    		continue;
        Set.insert(make_pair(tmp1, tmp2));
    }
    recursive(0, 0, p, q, c);
    cout<<steps<<'\n';
    return 0;
}
