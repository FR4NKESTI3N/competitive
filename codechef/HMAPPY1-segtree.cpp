#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Segment{
    int left, right, mid;
    Segment(int x = 0, int y = 0, int z = 0){
        left = x, mid = y, right = z;
    }

    bool operator ==(Segment x){
        return (left == x.left && mid == x.mid && right == x.right);
    }
}neg_seg = {-1, -1, -1};

class SegmentTree{
private:
    vector<Segment> st;
    vector<int> ar;
    int n;

    int left(int x){
        return x << 1;
    }

    int right(int x){
        return (x << 1) + 1;
    }

    void build(int p, int L, int R){
        if(L == R){
            if(ar[L] == 1)
                st[p] = {1, 1, 1};
            else
                st[p];
        }
        else{
            build(left(p), L, (L + R) >> 1);
            build(right(p), ((L + R) >> 1) + 1, R);
            st[p] = {st[left(p)].left, max(st[left(p)].mid, st[right(p)].mid), st[right(p)].right};
            st[p].mid = max(st[p].mid, st[left(p)].right + st[right(p)].left);
        }
    }

    Segment query(int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return neg_seg;
        if(L >= i && R <= j)
            return st[p];
        Segment p1 = query(left(p), L, (L + R) >> 1, i, j);
        Segment p2 = query(right(p), ((L + R) >> 1) + 1, R, i, j);
        if(p1 == neg_seg)
            return p2;
        if(p2 == neg_seg)
            return p1;
        Segment tmp = {p1.left, max(p1.mid, p2.mid), p2.right};
        tmp.mid = max(tmp.mid, p1.right + p2.left);
        return tmp;
    }

public:
    SegmentTree(vector<int> _a){
        ar = _a;
        n = ar.size();
        st.assign(4 * n, Segment());
        build(1, 0, n - 1);
    }

    int rsq(int i, int j){
        Segment tmp = query(1, 0, n - 1, i, j);
        return max(tmp.left, max(tmp.mid, tmp.right));
    }

    void show(){
        for(int i = 1; i <= 26; ++i){
            cout << i << '\t' << st[i].left << ' ' << st[i].mid << ' ' << st[i].right << '\n';
        }
    }
};

int main(){
    int n, Q, k;
    cin >> n >> Q >> k;
    vector<int> a(n), ar;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    ar = a;
    ar.insert(ar.end(), a.begin(), a.end());
    SegmentTree st(ar);
    string q;
    cin >> q;
    int t = 0;
    cout << st.rsq(0, 10) << "aaaa" << '\n';
    st.show();
    for(auto x : q){
        if(x == '?')
            cout << st.rsq(n - t, (2 * n) - 1 - t) << '\n';
        else{
            t = (t + 1) % n;
        }
    }
    return 0;
}
