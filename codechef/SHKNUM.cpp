#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int abs(int n){
    if(n < 0)
        return -n;
    return n;
}

int main(){
    vector<int> numbers;
    unsigned int num = 0;
    for(int i = 0; i <= 30; ++i){
        num = 1 << i;
        for(int j = 0; j < i; ++j){
            num += 1 << j;
            numbers.push_back(num);
            num -= 1 << j;
        }
    }
    int t, n, Min;
    cin >> t;
    while(t--){
        cin >> n;
        Min = 1 << 30;
        for(int i = 0; i < numbers.size(); ++i){
            Min = min(Min, abs(n - numbers[i]));
        }
        cout << Min << '\n';
    }
    return 0;
}
