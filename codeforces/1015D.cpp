#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main(){
    long long n, k, s;
    cin >> n >> k >> s;
    vector<long long> moves;
    ll dist, pos = 1;
    while(s){
        dist = n - 1;
        if(k == 1 || (s - dist) < k - 1){
            dist = s - k + 1;
        }
        if(dist >= n || dist <= 0){
            cout << "NO\n";
            return 0;
        }
        if(pos - dist >= 2){
            pos -= dist;
            moves.push_back(pos);
        }
        else if(pos + dist <= n){
            pos += dist;
            moves.push_back(pos);
        }
        else{
            pos -= dist;
            moves.push_back(pos);
        }
        if(pos < 1 || pos > n){
            cout << "NO\n";
            return 0;
        }
        s -= dist;
        --k;
    }
    if((s > 0) || (k > 0)){
        cout << "NO\n";
        return 0;
    }
    else{
        cout << "YES\n";
        for(auto x : moves)
            cout << x << ' ';
        cout << '\n';
    }
}
