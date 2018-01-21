#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <vector>

using namespace std;

int calc(string s){
    int k = 1;
    for(int i = 1; i < s.size(); i++){
        if(s[i-1]!=s[i])
            k++;
    }
    return k;
}


int memoization(vector<vector<int>> &memo, string a, string b, int i, int j){
    if(i==-1 || j==-1)
        return 0;
    if(memo[i][j]!=-1)
        return memo[i][j];
    if(a[i]==b[j]){
        memo[i][j] = 1+memoization(memo,a,b,i-1,j-1);
        // cout<<i<<' '<<j<<'\t'<<memo[i][j]<<'\n';
        return memo[i][j];
    }
    else{
        memo[i][j] = max(memoization(memo,a,b,i-1,j),memoization(memo,a,b,i,j-1));
        // cout<<i<<' '<<j<<'\t'<<memo[i][j]<<'\n';
        return memo[i][j];
    }
    return -1;
}

int max(std::vector<std::vector<int> > v){
    int m=-1;
    for(int i = 0; i < v.size() ; i++)
        for(int j = 0; j < v[i].size() ; j++)
            if(v[i][j]>m)
                m = v[i][j];
    return m;
}

int main(void){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t,n,m;
    cin>>t;
    while(t--){
        int ca=1,cb=1;
        cin>>n>>m;
        char temp;
        string a,b;
        cin>>temp;
        a.push_back(temp);
        for(int i = 1; i < n; i++){
            scanf("%c",&temp);
            if(temp!=a[a.size()-1]){
                a.push_back(temp);
                ca++;
            }
        }
        cin>>temp;
        b.push_back(temp);
        for(int i = 1; i < n; i++){
            scanf("%c",&temp);
            if(temp!=b[b.size()-1]){
                b.push_back(temp);
                cb++;
            }
        }
        n=a.size();
        m=b.size();
        vector<vector<int>> memo(n,vector<int> (m,-1));
        memoization(memo,a,b,n-1,m-1);
        int k = max(memo);
        cout<<ca+cb-k<<'\n';
    }
    return 0;
}
