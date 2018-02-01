#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void){
    int t;
    vector<int> a(4);
    cin>>t;
    while(t--){
        cin>>a[0]>>a[1]>>a[2]>>a[3];
        sort(a.begin(),a.end());
        if(a[1]==a[0] && a[2]==a[3]){
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
