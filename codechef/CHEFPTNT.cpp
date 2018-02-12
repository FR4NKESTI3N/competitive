#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main(void){
    int t,n,m,x,k;
    cin>>t;
    string s;
    while(t--){
        cin>>n>>m>>x>>k;
        cin>>s;
        pair<int, int> workers = {0,0};
        for(auto i : s)
            if(i == 'E')
                ++workers.first;
            else
                ++workers.second;
        int total_patents_filed = min(workers.first, (m / 2) * (min(x, workers.first)))
                                + min(workers.second, (m - (m / 2)) * (min(x, workers.second)));
        if(total_patents_filed >= n)
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
