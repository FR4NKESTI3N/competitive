#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main(void){
    short n,d,j,max = 0;
    string s, maxs;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        cin>>s>>d>>j;
        if(j-d > 0){
            max = j-d;
            maxs = s;
        }
    }
    printf("%s %d\n", maxs.c_str(), max);
    return 0;
}
