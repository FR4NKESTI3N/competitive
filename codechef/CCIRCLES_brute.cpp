#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;
typedef pair<int, int> pii;

double dist(int x1, int y1, int x2, int y2){
    return sqrt(((double)(x2 - x1) * (x2 - x1)) + ((double)(y2 - y1) * (y2 - y1)));
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<int> r(n), x(n), y(n);
    for(int i = 0; i < n; ++i)
        cin >> x[i] >> y[i] >> r[i];
    pair<vector<int>, vector<int>> interval;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            int rmax = max(r[i], r[j]), rmin = min(r[i], r[j]);
            if(x[i] == x[j] && y[i] == y[j]){
                interval.second.push_back(rmax - rmin);
                interval.first.push_back(rmax + rmin);
            }
            else{
                double distance = dist(x[i], y[i], x[j], y[j]);
                if(distance >= rmin + rmax){
                    interval.second.push_back(ceil(distance - rmax - rmin));
                    interval.first.push_back(floor(distance + rmin + rmax));
                }
                else if(rmax <= distance + rmin){
                    interval.second.push_back(ceil(0));
                    interval.first.push_back(floor(distance + rmin + rmax));
                }
                else{
                    interval.second.push_back(ceil(rmax - distance - rmin));
                    interval.first.push_back(floor(distance + rmax + rmin));
                }
            }
        }
    }
    vector<pii> tmp1(interval.first.size());
    for(int i = 0; i < tmp1.size(); ++i){
        tmp1[i].first = interval.first[i];
        tmp1[i].second = i;
    }
    sort(tmp1.begin(), tmp1.end());
    pair<vector<int>, vector<int>> tmp2 = interval;
    for(int i = 0; i < tmp1.size(); ++i){
        interval.first[i] = tmp2.first[tmp1[i].second];
        interval.second[i] = tmp2.second[tmp1[i].second];

    }
    vector<int> queries(q);
    unordered_map<int, int> result;
    for(int i = 0; i < q; ++i){
        cin >> queries[i];
    }
    vector<int> temp = queries;
    sort(queries.begin(), queries.end());
    for(int i = 0; i < q; ++i){
        int cnt = 0;
        for(int j = 0; j < interval.first.size(); ++j)
            if(queries[i] <= interval.first[j] && queries[i] >= interval.second[j])
                cnt++;
        result[queries[i]] = cnt;
    }
    for(auto x : temp)
        cout << result[x] << '\n';
    return 0;
}
