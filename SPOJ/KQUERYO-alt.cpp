#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

class SegmentTree{
    int n;
    vvi st;
    vi A;

    int left(int i){return i << 1;}
    int right(int i){return (i << 1) + 1;}

    int getDist(vi &a, int i){
        int n = a.size();
        int l = 0, r = n - 1, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(a[mid] <= i)
                l = mid + 1;
            else
                r = mid;
        }
        if(a[l] <= i)
            return 0;
        return n - l;
    }

    void build(int p, int L, int R){
        if(L == R){
            st[p] = vi(1, A[L]);
            return;
        }
        build(left(p), L, (L + R) >> 1);
        build(right(p), ((L + R) >> 1) + 1, R);
        merge(st[left(p)].begin(), st[left(p)].end(), st[right(p)].begin(), st[right(p)].end(), back_inserter(st[p]));
    }

    int query(int p, int L, int R, int i, int j, int val){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return getDist(st[p], val);
        int p1 = query(left(p), L, (L + R) >> 1, i, j, val);
        int p2 = query(right(p), ((L + R) >> 1) + 1, R, i, j, val);
        if(p1 == -1)
            return p2;
        if(p2 == -1)
            return p1;
        return p1 + p2;
    }

public:
    SegmentTree(vi A_){
        A = A_;
        n = A.size();
        st.assign(4*n, vi());
        build(1, 0, n - 1);
    }

    int query(int i, int j, int val){
        if(i > j)
            return 0;
        return query(1, 0, n - 1, i - 1, j - 1, val);
    }
};

int main(){
    int n, last_ans = 0, q, a, b, c;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0; i < n; ++i)
        cin >> ar[i];
    SegmentTree st(ar);
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> a >> b >> c;
        last_ans = st.query(max(1, a ^ last_ans), min(n, b ^ last_ans), c ^ last_ans);
        cout << last_ans <<'\n';
    }
    return 0;
}
