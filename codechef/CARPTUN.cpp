#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdio>

using namespace std;

int main(){
    int t, n, c, d;
    double s;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        long long temp = 0, mx = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d", &temp);
            if(temp > mx)
                mx = temp;
        }
        scanf("%d %d %d", &c, &d, &s);
        printf("%lld.000000000\n",(mx*(c-1)));
    }
    return 0;
}
