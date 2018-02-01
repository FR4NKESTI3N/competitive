#include <iostream>
#include <vector>

using namespace std;

int sum(int x){
    int s = 0;
    while(x){
        s+=x%10;
        x = x/10;
    }
    return s;
}

int main(void){
    int k;
    cin>>k;
    int n =1, ans = 19;
    while(n!=k){
        ans += 9;
        if(sum(ans)!=10)
            continue;
        else
            ++n;
    }
    cout<<ans<<'\n';
    return 0;
}
