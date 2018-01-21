#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(void){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        int mx=INT_MIN;
        vector<int> ar(n);
        long long sum = 0;
        for(int i = 0; i < n; i++){
            cin>>ar[i];
            sum+=ar[i];
            if(ar[i]>mx)
                mx= ar[i];
        }
        long long MAX = 0,MAX_ending_here = 0;
        for(int i = 0; i < k*n; i++){
            MAX_ending_here+= ar[i%n];
            if(MAX_ending_here < 0)
                MAX_ending_here = 0;
            if(MAX_ending_here>MAX)
                MAX = MAX_ending_here;
        }
        if(MAX==0)
            cout<<mx<<'\n';
        else
            cout<<MAX<<'\n';
    }
    return 0;
}
