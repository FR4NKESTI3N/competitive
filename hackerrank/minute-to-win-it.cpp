#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>

using namespace std;

int main(){
    long long n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    unordered_map<long long, int> count;
    for(int i = 0; i < n; ++i){
        long long start = a[i] - (k * i);
        if(count[start] == 0)
            count[start] = 1;
        else
            count[start]++;
    }
    int m = 0;
    for(unordered_map<long long, int> :: iterator it = count.begin(); it != count.end(); ++it)
        if(it->second > m)
            m = it->second;
    cout<<(n - m)<<'\n';
    return 0;
}
