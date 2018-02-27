#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n, temp;
    cin>>n;
    vector<int> ar(602);
    for(int i = 0; i < n; ++i){
        cin>>temp;
        ar[temp] = 1;
    }
    ar[0] = 0;
    int s = 0;
    for(int i = 1; i <= 600; ++i)
        s += ar[i];
    cout<<s<<'\n';
    return 0;
}
