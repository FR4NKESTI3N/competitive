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
        while(s != ts && p<=n){
            if(list[p]==2 || list[p]==0){
                p++;
                continue;
            }
            else if(p+s < ts){
                s+=p;
                list[p]=0;
                p++;
                continue;
            }
            else if(p+s==ts){
                s+=p;
                list[p]=0;

                p++;
                break;
            }
            else{
                int dif = s+p-ts;
                if(list[dif]==0){
                    list[dif]=1;
                    s+=p-dif;
                    list[p]=0;
                }
                else p++;
            }
        }
        if(s!=ts){
            memset(list,-1,(n+1)*sizeof(int));
            list[r]=2;
            if(list[n]!=2){
                list[n]=0;
                s=n;
            }
            else{
                s=n-1;
                list[n-1]=0;
            }
            int i;
            for(i = n-1; i > 0; i--){
                // cout<<"s= "<<s<<'\n';
                if(s+i-1 <= ts && list[i]!=2 && list[i]!=0){
                    s+=i-1;
                    list[i-1]=0;
                }
            }
            i=1;
            for(;i < n && s!=ts; i++){
                if(list[i]==2 || list[i]==0)
                    continue;
                if(s+i<=ts){
                    s+=i;
                    list[i]=0;
                    continue;
                }
                else{
                    int dif = s+i-ts;
                    if(list[dif]==0){
                        list[dif]=1;
                        list[i]=0;
                        s+=i-dif;
                        continue;
                    }
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(list[i]==0 || list[i]==2)
                cout<<list[i];
            else
                cout<<1;
        }
        cout<<'\n';
    }
    return 0;
}
