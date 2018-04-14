#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string s;
    cin >> s;
    int i = 0;
    while(s[i]!='0')
        i++;
    if(s[1] == '0'){
        cout<<s<<" 0\n";
        return 0;
    }
    vector<int> a(s.length() + 1), b(s.length() - i + 1);
    a[0] = 1;
    b[0] = 1;
    for(auto k : a)
        cout<<k;
    cout<<' ';
    for(auto k : b)
        cout<<k;
    cout <<'\n';
    return 0;
}
