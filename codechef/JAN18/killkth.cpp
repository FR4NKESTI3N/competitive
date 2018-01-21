#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    string s;
    vector<string> strs;
    string hidden;
    cin>>s;
    long long q,g=0,p,m,k;
    cin>>q;
    for(int i = 0; i < s.length(); i++){
        for(int j = i+1; j <= s.length(); j++){
            strs.push_back(s.substr(i,j-i));
        }
    }
    sort(strs.begin(),strs.end());
    for(auto a : strs)
        hidden+=a;
    while(q--){
        scanf("%ld %ld",&p,&m);
        k = (((p*g)%m) + m)%m + 1;
        g += hidden[k-1];
        printf("%c\n",hidden[k-1]);
    }

    return 0;

}
