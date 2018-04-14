#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <iterator>

using namespace std;

int main(){
    int t, n, k, temp;
    cin>>t;
    while(t--){
        int flag = 0;
        long long sum = 0;
        cin>>n>>k;
        map<int, int> m;
        for(int i = 0; i < n; ++i){
            cin>>temp;
            if(m.find(temp) == m.end()){
                m.insert(make_pair(temp, 1));
            }
            else
                m[temp]++;
        }
        map<int, int> :: iterator it;
        for(it = m.begin(); it != m.end(); it++){
            if(it->second == k){
                sum += it->first;
                flag = 1;
            }
        }
        if(flag)
            cout<<sum<<'\n';
        else
            cout<<"-1\n";
    }
    return 0;
}
