#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int list[1000001];

int main(void){
    int t;
    ll n,r;
    cin>>t;
    while(t--){
        cin>>r>>n;
        ll ts = (n*(n+1))/2 - r;
        // cout<<"ts= "<<ts<<endl;
        if((ts)%2 || n==2 || n==3){
            cout<<"impossible\n";
            continue;
        }

        ts /= 2;
        memset(list, -1, (n+1)*sizeof(int));
        ll s = 0;
        for(int i = 1; i < n/2; i++){
            s+=i;
            list[i]=0;
        }
        list[r]=2;
        if(r < n/2)
            s-=r;
        int p = n/2;
        // cout<<"s= "<<s<<'\n';
        while(s != ts && p<=n){
            // cout<<"checking for "<<p<<'\n';
            if(list[p]==2 || list[p]==0){
                // cout<<"ignoring "<<p<<'\n';
                p++;
                continue;
            }
            else if(p+s < ts){
                s+=p;
                list[p]=0;
                p++;
                // cout<<"adding "<<p<<'\n';
                continue;
            }
            else if(p+s==ts){
                s+=p;
                list[p]=0;
                // cout<<"found at "<<p<<'\n';

                p++;
                break;
            }
            else{
                int dif = s+p-ts;
                if(list[dif]==0){
                    list[dif]=1;
                    s-=dif;
                    s+=p;
                    list[p]=0;
                    // cout<<"replacing "<<dif<<" with "<<p<<'\n';
                }
                else p++;
            }
        }
        for(int i = 1; i <= n; i++){
            if(list[i]==0 || list[i]==2)
                cout<<list[i];
            else cout<<1;
        }
        cout<<'\n';
    }
    return 0;
}