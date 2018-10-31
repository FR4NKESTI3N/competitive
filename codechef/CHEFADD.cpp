#include <iostream>
#include <vector>
#include <set>

using namespace std;
inline int bitCount(int x){
    int count = 0;
    for(int i = 0; i < 30; ++i)
        if(x & (1 << i))
            ++count;
    return count;
}


int main(){
    vector<set<int>> mat(32);
    for(int i = 1; i <= 100000; ++i){
        mat[bitCount(i)].insert(i);
    }
    int t, a, b, c;
    cin >> t;
    while(t--){
        int count = 0;
        cin >> a >> b >> c;
        int A = bitCount(a), B = bitCount(b);
        for(auto x : mat[A]){
            if(mat[B].find(c - x) != mat[B].end())
                ++count;
        }
        cout << count << '\n';
    }
    return 0;
}
