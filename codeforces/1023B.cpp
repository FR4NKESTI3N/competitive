#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long n, m, pos_avail;
    cin >> n >> m;
    if(m % 2)
        pos_avail = m / 2;
    else
        pos_avail = ((m - 1) / 2);
    if(n <= (m / 2))
        cout << "0\n";
    else if(n >= m)
        cout << pos_avail << '\n';
    else
        cout << pos_avail - m + 1 + n << '\n';
    return 0;
}
