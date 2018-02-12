#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    string s;
    while(t--){
        vector<vector<int>> count(26);
        int codd = 0;
        cin>>s;
        for(int i = 0; i < s.size(); ++i)
            count[s[i] - 'a'].push_back(i);
        for(auto i : count){
            if(i.size()%2)
                ++codd;
        }
        if(codd > 1 || ((codd > 0) && !(s.size()%2))){
            cout<<"-1\n";
            continue;
        }
        vector<int> x(s.size());
        int i = 0, j = s.size() - 1;
        for(int k = 0; k < 26; ++k){
            if(count[k].size()%2){
                x[s.size()/2] = count[k][count[k].size() - 1];
                count[k].pop_back();
            }
            for(int l = 0; l < count[k].size(); l+=2){
                x[i] = count[k][l];
                x[j] = count[k][l+1];
                ++i;--j;
            }
        }
        for(auto i : x)
            cout<<i + 1<<' ';
        cout<<'\n';
    }
    return 0;
}
