#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <utility>

using namespace std;

class SegmentTreeMin{
protected:
    vector<int> st;
    int n;
    int left(int p){return p << 1;}
    int right(int p){return (p << 1) + 1;}

    int comp(int p1, int p2){
        return (A[p1] <= A[p2]) ? p1 : p2;
    }

    void build(int p, int L, int R){
        if(L == R)
            st[p] = L;
        else{
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = comp(p1, p2);
        }
    }

    int RMQ(int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];
        int p1 = RMQ(left(p), L, (L + R)/2, i, j);
        int p2 = RMQ(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1)
            return p2;
        if(p2 == -1)
            return p1;
        return comp(p1,p2);
    }

public:
    vector<int> A;
    SegmentTreeMin(vector<int> &_A){
        A = _A;
        n = A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }

    int get_n(){return n;}

    int rmq(int i, int j){
        return RMQ(1,0, n - 1, i, j);
    }

    int update(int p, int L, int R, int idx, int new_val){
        int i = idx, j = idx;
        if (i > R || j < L)
          return st[p];
        if (L == i && R == j) {
        A[i] = new_val;
        return st[p] = L;
        }
        int p1, p2;
        p1 = update(left(p), L, (L + R)/2, idx, new_val);
        p2 = update(right(p), (L + R)/2 + 1, R, idx, new_val);
        st[p] = comp(p1, p2);
        return st[p];

    }

    int update(int idx, int new_val){
        return update(1, 0, n - 1, idx, new_val);
    }
};


//To do : use function pointer or something instead of 2 classes

class SegmentTreeMax{
protected:
    vector<int> st;
    int n;
    int left(int p){return p << 1;}
    int right(int p){return (p << 1) + 1;}

    int comp(int p1, int p2){
        return (A[p1] >= A[p2]) ? p1 : p2;
    }

    void build(int p, int L, int R){
        if(L == R)
            st[p] = L;
        else{
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = comp(p1, p2);
        }
    }

    int RMQ(int p, int L, int R, int i, int j){
        if(i > R || j < L)
            return -1;
        if(L >= i && R <= j)
            return st[p];
        int p1 = RMQ(left(p), L, (L + R)/2, i, j);
        int p2 = RMQ(right(p), (L + R)/2 + 1, R, i, j);

        if(p1 == -1)
            return p2;
        if(p2 == -1)
            return p1;
        return comp(p1,p2);
    }

public:
    vector<int> A;
    SegmentTreeMax(vector<int> &_A){
        A = _A;
        n = A.size();
        st.assign(4 * n, 0);
        build(1, 0, n - 1);
    }


    int get_n(){return n;}

    int rmq(int i, int j){
        return RMQ(1,0, n - 1, i, j);
    }

};


inline bool condition(SegmentTreeMin &st_a, SegmentTreeMax &st_b, int L, int R, int lower_limit){
    return st_b.A[st_b.rmq(L, R)] <= lower_limit && st_a.A[st_a.rmq(L, R)] >= lower_limit;
}

int bSearch(vector<int> v, int key){
    int l = 0, r = v.size() - 1, mid;
    while(l <= r){
        mid = (l + r)>>1;
        if(v[mid] == key)
            return mid;
        else if(v[mid] > key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int main(){
    int t, n;
    cin >> t;
    while(t--){
        bool flag = 0;
        cin >> n;
        int steps = 0;
        vector<int> a(n), b(n), visited(n, 0);
        unordered_map<int, vector<int> > map;
        for(int i = 0; i < n; ++ i)
            scanf("%d", &a[i]);
        for(int i = 0; i < n; ++ i){
            scanf("%d", &b[i]);
            if(map.find(b[i]) == map.end()){
                map.insert(make_pair(b[i], vector<int> (1, i)));
            }
            else
                map[b[i]].push_back(i);
        }
        SegmentTreeMin st_a(a);
        SegmentTreeMax st_b(b);

        for(int i = 0; i < n; ++i){
            if(a[i] < b[i]){
                flag = 1;
                break;
            }
            if(visited[i] || a[i] == b[i])
                continue;
            int R;
            int I = bSearch(map[b[i]], i);
            for(; I < map[b[i]].size(); ++I){
                if(!condition(st_a, st_b, i, map[b[i]][I], b[i]))
                    break;
                visited[map[b[i]][I]] = 1;
            }
            steps++;
        }
        if(flag)
            cout<<"-1\n";
        else
            cout<<steps<<'\n';
    }
    return 0;
}
