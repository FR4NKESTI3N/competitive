#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;
typedef pair<int, int> pii;

int main(){
    int n, m, tmp1, tmp2;
    cin >> n >> m;
    vector<pii> data(n, make_pair(0, 0));
    vector<int> votes(m + 1, 0);
    for(int i = 0; i < n; ++i){
        cin >> tmp1 >> tmp2;
        ++votes[tmp1];
        if(tmp1 != 1)
            data[i] = pii({tmp2, tmp1});
        else{
            --i;
            --n;
        }
    }
    sort(data.begin(), data.end());
    int index = 0, mx = 1, mxi = n - 1;
    long long cost = 0;
    for(int i = 1; i <= m; ++i){
        if(votes[mx] < votes[i])
            mx = i;
        else if(votes[mx] == votes[i] && mx == 1)
            mx = i;
    }
    while(mx != 1){
        if(data[index].second == 0){
            ++index;
            continue;
        }
        for(int i = index; i < n; ++i)
            if(data[i].second == mx){
                mxi = i;
                break;
            }

        if(index == mxi){
            cout << "="<<data[index].second << '\n';

            votes[1]++;
            votes[mx]--;
            for(int i = 1; i <= m; ++i){
                if(votes[mx] < votes[i])
                    mx = i;
                else if(votes[mx] == votes[i] && mx == 1)
                    mx = i;
            }
            cost += data[index].first;
            ++index;
            continue;
        }
        if(data[index + 1].second == mx && votes[1] < votes[mx]){
            cout << "=="<<data[index + 1].second << ' '<<votes[1]<<' '<<votes[mx]<<'\n';

            votes[1]++;
            votes[mx]--;
            for(int i = 1; i <= m; ++i){
                if(votes[mx] < votes[i])
                    mx = i;
                else if(votes[mx] == votes[i] && mx == 1)
                    mx = i;
            }
            cost += data[index + 1].first;
            data[index + 1] = data[index];
            ++index;
            continue;
        }
        if((data[index + 1].first + data[index].first > data[mxi].first) && votes[1] < votes[mx]){
            cout << "==="<<data[index + 2].second << '\n';

            votes[1]++;
            votes[mx]--;
            for(int i = 1; i <= m; ++i){
                if(votes[mx] < votes[i])
                    mx = i;
                else if(votes[mx] == votes[i] && mx == 1)
                    mx = i;
            }
            cost += data[mxi].first;
            for(int k = mxi; k > index; --k){
                data[k] = data[k - 1];
            }
            ++index;
            continue;
        }
        cout << "===="<<data[index].second << '\n';

        votes[1]++;
        votes[data[index].second]--;
        cost += data[index].first;
        ++index;
        for(int i = 1; i <= m; ++i){
            if(votes[mx] < votes[i])
                mx = i;
        }
    }
    cout << cost << '\n';
    return 0;
}
