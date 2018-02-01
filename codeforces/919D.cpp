#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

vector<int> vals;
vector<vector<int>> links;

int main(void){
    int n, m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(auto a : s){
        vals.push_back(a - 'a');
    }
    
    return 0;
}
