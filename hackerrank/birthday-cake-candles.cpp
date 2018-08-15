#include <iostream>

using namespace std;

int main(){
    int n, max = 0, cnt = 0, temp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        if(temp == max)
            ++cnt;
        else if(temp > max){
            max = temp;
            cnt = 1;
        }
    }
    cout << cnt << '\n';
}
