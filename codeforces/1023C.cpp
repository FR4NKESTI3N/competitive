#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string t = "";
    int idx = 0;
    int cnt0 = 0, cnt1 = 0;
    while(cnt0 < k / 2){
        if(s[idx] == '(')
            ++cnt0;
        else
            ++cnt1;
        t.push_back(s[idx++]);
    }
    while(cnt1 != cnt0){
        t.push_back(')');
        cnt1++;
    }
    cout << t <<'\n';
    return 0;
}
