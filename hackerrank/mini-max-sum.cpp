#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(){
    vector<int> a(5);
    for(int i = 0; i < 5; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    long long sum = accumulate(a.begin(), a.end(), (long long)0);
    cout << sum - a[4] << ' ' << sum - a[0] << '\n';
    return 0;
}
