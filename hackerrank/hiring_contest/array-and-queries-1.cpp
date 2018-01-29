#include <iostream>
#include <vector>
#include <cstdio>
#include <utility>
#include <map>
#include <iterator>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef long long ll;

const ll MOD = 1000000007;

map <int, int> ar;
map <int, int> :: iterator itr;

ll pairs = 0, cur = 0, ans = 0;


void removed(map <int, int> :: iterator iter){
    if(iter->first == prev(iter)->first + 1){
        if(iter->first == next(iter)->first - 1){
            if((iter->second <= prev(iter)->second) && (iter->second <= next(iter)->second)){
                pairs += 1;
            }
            else if((iter->second > prev(iter)->second) && (iter->second > next(iter)->second)){
                pairs -= 1;
            }
        }
        else if(iter->second > prev(iter)->second){
            pairs -= 1;
        }
    }
    else if(iter->first == next(iter)->first - 1){
        if(iter->second > next(iter)->second){
            pairs -= 1;
        }
    }
    else{
        pairs -= 1;
    }
    iter->second -= 1;
    return;
}

void added(map <int, int> :: iterator iter){
    if(iter->first == prev(iter)->first + 1){
        if(iter->first == next(iter)->first - 1){
            if((iter->second <= prev(iter)->second) && (iter->second <= next(iter)->second)){
                pairs -= 1;
            }
            else if((iter->second > prev(iter)->second) && (iter->second > next(iter)->second)){
                pairs += 1;
            }
        }
        else if(iter->second > prev(iter)->second){
            pairs += 1;
        }
    }
    else if(iter->first == next(iter)->first - 1){
        if(iter->second > next(iter)->second){
            pairs += 1;
        }
    }
    else{
        pairs += 1;
    }
}

int main(void){
    int n, q;
    ar.insert(make_pair(0,0));
    ar.insert(make_pair(1000000001,0));
    scanf("%d", &n);
    vi a(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
        itr = ar.find(a[i]);
        if(itr == ar.end()){
            ar.insert(make_pair(a[i], 1));
        }
        else
            ++itr->second;
    }
    for(itr = next(ar.begin()); itr != ar.end(); ++itr){
        if(itr->first == (prev(itr))->first + 1){
            if(cur == itr->second)
                continue;
            if(cur > itr->second){
                pairs += cur - itr->second;
                cur = itr->second;
            }
            else{
                cur = itr->second;
            }
        }
        else{
            pairs += cur;
            cur = itr->second;
        }
    }
    scanf("%d", &q);
    int id, new_val, old_val;
    for(int i = 1; i <= q; ++i){
        scanf("%d %d", &id, &new_val);
        --id;
        itr = ar.find(a[id]);
        removed(itr);
        a[id] = new_val;
        itr = ar.find(a[id]);
        if(itr == ar.end()){
            ar.insert(make_pair(a[id], 1));
            itr = ar.find(a[id]);
        }
        else{
            ++itr->second;
        }
        added(itr);
        ans += pairs*i;
        ans%= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
