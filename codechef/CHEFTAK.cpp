#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int tt;
    cin >> tt;
    while(tt--){
    double n, t, y, z;
    double x = 10, xx = 0;
    cin >> n;

    while(n--){
        cin >> t >> y >> z;
        if(t == 1){
            cout << min(xx * z, (double)y) << '\n';
            x += min(xx * z, (double)y) * 0.0005;
            xx -= min(xx, ((double)y) / z);
        }
        else{
            cout << min(x, (double)y) << '\n';
            xx += (((double)min(x, (double)y)) / z) * 0.0005;
            x -= min(x, (double)y);
        }
    }
    }
    // cout << xx;
    return 0;
}
