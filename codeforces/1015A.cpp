#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int main(){
    int n, m, tmp1, tmp2;
    cin >> n >> m;
    vector<int> points(m + 1, 1);
    points[0] = 0;
    for(int i = 0; i < n; ++i){
        cin >> tmp1 >> tmp2;
        for(int j = tmp1; j <= tmp2; ++j)
            points[j] = 0;
    }
    int k = 0;
    vector<int> pts;
    for(int i = 1; i <= m; ++i){
        if(points[i]){
            ++k;
            pts.push_back(i);
        }
    }
    cout << k << '\n';
    for(auto x : pts)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
