#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, tmp;
    cin>>t;
    while(t--){
        long long pairs = 0;
        cin>>n;
        vector<long long> count(2001, 0);
        for(int i = 0; i < n; ++i){
            cin>>tmp;
            ++count[tmp + 1000];
        }
        for(auto a : count){
            pairs+=(a*(a-1))/2;
        }
        for(int i = 0; i < 2000; ++i){
            if(count[i]){
                for(int j = i + 2; j <= 2000; j+=2){
                    if(count[(i + j)/2])
                        pairs+=count[i]*count[j];
                }
            }
        }
        cout<<pairs<<'\n';
    }
    return 0;
}
