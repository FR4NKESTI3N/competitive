#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void swap (char &a, char &b){
    char tmp = a;
    a = b;
    b = tmp;
}

int main(){
    int n;
    string s, t;
    cin >> n >> s >> t;
    string ss = s, tt = t;
    sort(ss.begin(), ss.end());
    sort(tt.begin(), tt.end());
    if(ss != tt){
        cout << "-1\n";
        return 0;
    }
    if(s == t){
        cout << "0\n";
        return 0;
    }
    char c;
    vector<int> moves;
    for(int i = 0; i < n; ++i){
        int k = i;
        while(s[k] != t[i])
            ++k;
        for(int j = k; j > i; --j){
            moves.push_back(j);
            swap(s[j], s[j - 1]);
        }
    }
    cout << moves.size() << '\n';
    for(auto x : moves)
        cout << x << ' ';
    cout << '\n';
    return 0;
}
