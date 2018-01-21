#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int maxlt(vector<int> ar, int limit){
    int MAX = -1;
    for(int i = 0; i < ar.size(); i++){
        if(ar[i]<limit && ar[i]>MAX)
            MAX = ar[i];
    }
    return MAX;
}

int main(void){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long sum = 0;
        vector<vector<int>> mat(n,vector<int> (n,0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin>>mat[i][j];
        int x = INT_MAX;
        for(int i = n-1; i >= 0; i--){
            x = maxlt(mat[i],x);
            if(x==-1){
                cout<<"-1\n";
                break;
            }
            sum+=x;
        }
        if(x!=-1)
            cout<<sum<<'\n';
    }
    return 0;
}
