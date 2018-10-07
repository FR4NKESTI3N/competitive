#include <cstdio>

int main(){
    int s;
    int dump = std :: scanf("%d", &s);
    if(s <= 90){
        std :: printf("0 No punishment");
        return 0;
    }
    if(s <= 110)
        std :: printf("%d Warning", 300 * (s - 90));
    else
        std :: printf("%d License removed", 500 * (s - 90));
    return 0;
}
