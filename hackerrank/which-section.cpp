#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t, n, k, m, temp;
    cin>>t;
    while(t--){
        cin>>n>>k>>m;
        vector<int> a(m + 1);
        int sum = 0;
        for(int i = 0; i < m; ++i)
            cin>>a[i];
        a[m] = n;
        for(int i = 0; i < m; ++i){
            sum += a[i];
            if(sum >= k){
                cout<<(i + 1)<<'\n';
                break;
            }
        }
    }
    return 0;
}
