#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <utility>
#include <cstring>

using namespace std;


typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
vi dead((1<<17) + 1);
int mask;

int LSOne(int x){
    return (x & (-x));
}

ll offset[19] = {0, 0, 2, 9, 40, 205, 1236, 8659, 69280, 623529, 6235300, 68588311, 823059744, 10699776685, 149796873604,
    2246953104075, 35951249665216, 611171244308689, 11001082397556420};

int visited[(1<<17) + 1];

class FenwickTree{
private: vi ft;
public: FenwickTree(int n){ft.assign(n+1,0);}
    int rsq(int b){
        int sum = 0;
        for(; b; b-= LSOne(b))
            sum+=ft[b];
        return sum;
    }
    int rsq(int a, int b){
        return rsq(b) - (a==1?0:rsq(a-1));
    }
    void update(int k, int v){
        for(; k <(int)ft.size(); k+=LSOne(k))
            ft[k]+=v;
    }
    int get(int i){
        return ft[i];
    }
};

struct node{
    int health = 0;
    vi children;
};

int bin_search(FenwickTree ft, int h,int low, int high){
    int mid = (low+high)/2;
    if(ft.rsq(mid) >= h && ft.rsq(mid-1) < h){
        return mid;
    }
    else if(ft.rsq(mid-1)>=h)
        return bin_search(ft,h,low, mid-1);
    else return bin_search(ft,h,mid+1, high);
}

void calc(int x, vvi queries, FenwickTree ft, vector<struct node> graph){
    if(visited[x] == 1)
        return;
    for(auto a : queries){
        if(a[1] == x)
            ft.update(a[0]+1, a[2]);
    }
    if(graph[x].health>0){
        int m = bin_search(ft, graph[x].health, 1, queries.size());
        dead[m]++;
    }
    visited[x] = 1;
    for(auto a : graph[x].children)
        calc(a,queries,ft,graph);
}

int main(void){
    int n,q,x,y,k;
    cin>>n;
    for(k = 0; k <= 19 && (1<<k)<n; k++);
    mask = (1<<k) -1;
    vector<struct node> graph(mask + 1);
    for(int i = 0; i < n; i++)
        scanf("%d",&graph[i].health);
    cin>>q;
    for(int i = 0; i <=mask; i++){
        for(int j = 0; j <= 19 && (1<<j) < i; j++){
            if(i & (1 << j)){
                graph[i].children.push_back(i & (~(1 << j)));
            }
        }
    }
    vvi queries;
    vi temp(3);
    for(temp[0] = 1; temp[0] <= q; temp[0]++){
        scanf("%d %d", &temp[1], &temp[2]);
        temp[1]&=mask;
        if(graph[0].health > 0){
            graph[0].health-=temp[2];
            if(graph[0].health<=0)
                dead[temp[0]]++;
        }
        queries.push_back(temp);
    }
    temp[1] = mask;
    temp[2] = 1000000000;
    queries.push_back(temp);
    temp[0] = 0;
    temp[1] = mask;
    temp[2] = 0;
    queries.push_back(temp);
    FenwickTree ft(q+2);
    sort(queries.begin(), queries.end(), [](const auto& lhs, const auto& rhs){
        return lhs[1]>rhs[1];
    });
    memset(visited,0,sizeof(int)*(mask + 1));
    calc(mask,queries,ft,graph);
    int d = 0;
    for(int i = 3; i <= q + 2; i++){
        d+=dead[i];
        printf("%d\n",n-d);
    }
    return 0;
}
