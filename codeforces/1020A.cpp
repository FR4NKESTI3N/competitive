#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    int ta, fa, tb, fb;
    int time;
    for(int i = 0; i < k; ++i){
        time = 0;
        cin >> ta >> fa >> tb >> fb;
        while(ta != tb){
            if(fa <= b && fa >= a){
                time += abs(ta - tb);
                ta = tb;
            }
            else{
                if(fa < a){
                    time += a - fa;
                    fa = a;
                }
                else{
                    time += fa - b;
                    fa  = b;
                }
            }
        }
        time += abs(fa - fb);
        cout << time << '\n';
    }
    return 0;
}
