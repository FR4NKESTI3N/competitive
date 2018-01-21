#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstring>
#include <utility>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct node{
    int health = 0;
    vi children;
};

int dead = 1;
int visited[(1<<18) + 1];
void sub(int x, vector<struct node>& nodes){
    if(visited[x] == 1)
        return;
    if(nodes[x].health == 1){
        nodes[x].health = 0;
        dead++;
    }
    visited[x]=1;
    for(auto a : nodes[x].children)
        sub(a,nodes);
    return;
}

int main(void){
    int n,q,x,y;
    scanf("%d",&n);
    int k;
    for(k = 0; k <= 19 && (1<<k)<=n; k++);
    int mask = (1<<k) -1;
    vector<struct node> nodes(mask+1);
    for(int i = 0; i < n; i++){
        scanf("%d",&nodes[i].health);
    }
    for(int i = mask; i > 0; i--){
        for(int j = 0; j <= k && (1<<j)<i; j++){
            if(i & (1<<j))
                nodes[i].children.push_back(i & ~(1<<j));
        }
    }
    memset(visited, 0 ,sizeof(int) * (mask+1));
    visited[0]=1;
    scanf("%d",&q);
    if(n<=1025){
        dead = 0;
        while(q--){
            scanf("%d %d",&x,&y);
            x&=mask;
            for(int i = x; i>=0; i--){
                if((i&x) == i){
                    if(nodes[i].health > 0){
                        nodes[i].health -= y;
                        if(nodes[i].health <=0 ){
                            dead++;
                        }
                    }
                }
            }
            printf("%d\n",n-dead);
        }
        return 0;
    }
    while(q--){
        scanf("%d %d",&x,&y);
        x&=mask;
        sub(x,nodes);
        printf("%d\n",n-dead);
    }
    return 0;
}
