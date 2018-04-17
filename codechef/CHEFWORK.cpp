#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m1 = 100001, m2 = 100001, m3 = 100001;
    cin>>n;
    vector<int> cost(n), type(n);
    for(int i = 0; i < n; ++i)
        cin>>cost[i];
    for(int i = 0; i < n; ++i)
        cin>>type[i];
    for(int i = 0; i < n; ++i){
        if(type[i] == 1 && m1 > cost[i])
            m1 = cost[i];
        if(type[i] == 2 && m2 > cost[i])
            m2 = cost[i];
        if(type[i] == 3 && m3 > cost[i])
            m3 = cost[i];
    }
    cout<<min(m1 + m2, m3)<<'\n';
    return 0;
}
