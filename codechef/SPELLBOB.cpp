#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int t, flag;
    string s = "000", s1, s2;
    cin >> t;
    while(t--){
        flag = 0;
        cin >> s1 >> s2;
        for(int i = 0; i < 8; ++i){
            if(i & 1)
                s[0] = s1[0];
            else
                s[0] = s2[0];
            if((i >> 1) & 1)
                s[1] = s1[1];
            else
                s[1] = s2[1];
            if((i >> 2) & 1)
                s[2] = s1[2];
            else
                s[2] = s2[2];
            sort(s.begin(), s.end());
            if(s == "bbo"){
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}
