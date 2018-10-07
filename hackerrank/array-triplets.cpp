#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <set>

using namespace std;

long long subsetSum(vector<int> ar, int subset){
    int n = ar.size();
    long long S = 0;
    for(int i = 0; i < n; ++i){
        if(subset & (1 << i))
            S += ar[i];
    }
    return S;
}

int ones(int x){
    int count = 0;
    for(int i = 0; (1 << i) <= x; ++i)
        if(x && (1 << i))
            ++count;
    return count;
}

int main(){
    int n;
    int count = 0;
    cin >> n;
    vector<int> ar(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> ar[i];
    sort(ar.begin(), ar.end());
    set<set<int>> encountered_sets;
    set<int> sets;
    long long target = subsetSum(ar, (1 << n) - 1);
    // cout << target << '\n';
    if(target % 3){
        cout << "0\n";
        return 0;
    }
    target /= 3;
    for(int subset_1 = 1; subset_1 < (1 << n); ++subset_1){
        if(subsetSum(ar, subset_1) != target)
            continue;
        for(int subset_2 = subset_1 + 1; subset_2 < (1 << n); ++subset_2){
            if((subset_2 & subset_1) == 0 && subsetSum(ar, subset_2) == target){
                set<int> S({subset_1, subset_2, (((1 << n) - 1) ^ subset_1 ^ subset_2)});
                if(encountered_sets.find(S) == encountered_sets.end()){
                    encountered_sets.insert(S);
                }
            }
        }
    }
    cout << encountered_sets.size() * 6 << '\n';
    // int N = n;
    // for(int subset = 1; subset < (1 << n); ++subset)
    //     if(subsetSum(ar, subset) == target)
    //         sets.insert(subset);
    // vector<int> setss;
    // for(auto x : sets)
    //     setss.push_back(x);
    // n = setss.size();
    // for(int i = 0; i < n; ++i){
    //     for(int j = i + 1; j < n; ++j)
    //         for(int k = j + 1; k < n; ++k){
    //             if(((setss[i] & setss[j] & setss[k]) == 0) && ((setss[i] | setss[j] | setss[k]) == (1 << N) - 1))
    //                 count += 6;
    //         }
    // }
    // cout << sets.size() << ' ' <<count <<'\n';
    return 0;
}
