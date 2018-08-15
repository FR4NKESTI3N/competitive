#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

vector<pii> subtask_info;

int main(){
    int p, s;
    cin >> p >> s;
    vector<pii> score(p, pii({0, 0}));
    for(int i = 1; i <= p; ++i){
        score[i - 1].second = i;
    }
    subtask_info.assign(s, pii({0, 0}));
    for(int i = 0; i < p; ++i){
        for(int j = 0; j < s; ++j)
            cin >> subtask_info[j].first;
        for(int j = 0; j < s; ++j)
            cin >> subtask_info[j].second;
        sort(subtask_info.begin(), subtask_info.end());
        for(int j = 1; j < s; ++j){
            if(subtask_info[j - 1].second > subtask_info[j].second)
                ++score[i].first;
        }
    }
    stable_sort(score.begin(), score.end());
    for(int i = 0; i < p; ++i)
        cout << score[i].second << '\n';
    return 0;
}
