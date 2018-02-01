#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<numeric>

using namespace std;

typedef vector<int> vi;
typedef long long ll;


int main(){
    int n;
    cin>>n;
    vi l(n),b(n);
    for(int i = 0; i < n; i++)
        scanf("%d",&l[i]);
    for(int i = 0; i < n; i++)
        scanf("%d",&b[i]);
    ll sum = accumulate(l.begin(), l.end(),0);
    return 0;
}
