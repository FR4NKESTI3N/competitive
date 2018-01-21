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
        for(int i = 0; i < n; i++){
            MAX_ending_here+= ar[i%n];
            if(MAX_ending_here < 0)
                MAX_ending_here = 0;
            if(MAX_ending_here>MAX)
                MAX = MAX_ending_here;
        }
        long long u1 = MAX;
        for(int i = n; i < 2*n; i++){
            MAX_ending_here+= ar[i%n];
            if(MAX_ending_here < 0)
                MAX_ending_here = 0;
            if(MAX_ending_here>MAX)
                MAX = MAX_ending_here;
        }
        long long u2 = MAX;
        for(int i = 2*n; i < 3*n; i++){
            MAX_ending_here+= ar[i%n];
            if(MAX_ending_here < 0)
                MAX_ending_here = 0;
            if(MAX_ending_here>MAX)
                MAX = MAX_ending_here;
        }
        long long u3 = MAX;
        for(int i = 3*n; i < 4*n; i++){
            MAX_ending_here+= ar[i%n];
            if(MAX_ending_here < 0)
                MAX_ending_here = 0;
            if(MAX_ending_here>MAX)
                MAX = MAX_ending_here;
        }
        long long u4 = MAX;
        if(MAX==0){
            cout<<mx<<'\n';
            continue;
        }
        if(k==1){
            cout<<u1<<'\n';
            continue;
        }
        if(k==2){
            cout<<u2<<'\n';
            continue;
        }
        if(u3==u4)
            cout<<u2<<'\n';
        else cout<<(u4+(k-4)*sum)<<'\n';
    }
    return 0;
}
