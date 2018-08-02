#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> pii;

int main(){
    long long n, m;
    cin >> n >> m;
    vector<pii> list(n);
    vector<int> delta;
    long long original_size = 0, songs_compressed = 0;
    for(int i = 0; i < n; ++i){
        cin >> list[i].first >> list[i].second;
        delta.push_back(list[i].first - list[i].second);
        original_size += list[i].first;
    }
    sort(delta.begin(), delta.end());
    int k = n - 1;
    while(original_size > m && k >= 0){
        original_size -= delta[k--];
        ++songs_compressed;

    }
    cout << ((original_size > m) ? - 1 : songs_compressed) << '\n';
    return 0;
}
