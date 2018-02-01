#include <iostream>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

int main(void){
    int n, q, max_bit = 0;
    scanf("%d", &n);
    for(; (1<<max_bit) <= n; ++max_bit);
    int mask = (1<<max_bit) - 1;
    vi health(mask + 1, 0);
    for(int i = 0; i < n; i++)
        scanf("%d", &health[i]);
    scanf("%d", &q);

    int blocks_size = 2048;
    int block_count = (q/blocks_size) + 1;
    vvi block(blocks_size, vi(2,0));
    vi death_at(q, 0);
    int health_deductions[mask + 1];
    int traversed = 0;



    int alive = n;
    for(int i = 0; i < death_at.size(); ++i)
        printf("%d\n", alive-=death_at[i]);
    return 0;
}
