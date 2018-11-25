#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

long long f(long long n){
    long long x = 1;
    x += (n * n - n) * 3;
    return x;
}

int main(){
    int t;
    cin >> t;
    vector<long long> Q, ans;
    ofstream o, i;
    o.open("out.txt");
    i.open("in.txt");
    o << t << '\n';
    while(t){
        cout << t << '\n';
        srand(time(0) * t + t);
        //500000000
        long long x = (rand() + 10000000) % ((long long)10000000) + 100;
        if(x <= 1)
            continue;
        long long y = f(x), z = f(x - 1);
        long long q = z + (rand() + (y - z)) % (y - z);
        Q.push_back(q);
        ans.push_back(x - 2);
        --t;
    }
    for(auto x : Q)
        o << x << '\n';
    for(auto x : ans)
        i << x << '\n';

    return 0;
}
