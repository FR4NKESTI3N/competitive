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


int memoization(vector<vector<int>> &memo, string a, string b){
    int m=a.length(), n = b.length();
    for(int i = 0;i <= m; i++){
        for(int j = 0; j <= n; j++){
            if(i==0 || j == 0)
                memo[i][j]=0;
            else if(a[i-1] == b[j-1])
                memo[i][j] = memo[i-1][j-1] + 1;
            else
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
        }
    }
    return memo[m][n];
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
        vector<vector<int>> memo(n+1,vector<int> (m+1,-1));
        memoization(memo,a,b);
        int k = max(memo);
        cout<<ca+cb-k<<'\n';
    }
    return 0;
}
