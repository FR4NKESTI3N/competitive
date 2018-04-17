#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

const double MIN_DIST = 0.000001;

int main(){
    int T, n;
    double s, y;
    cin>>T;
    while(T--){
        cin>>n>>s>>y;
        vector<int> v(n), d(n), p(n), c(n);
        for(int i = 0; i < n; ++i)
            cin>>v[i];
        for(int i = 0; i < n; ++i){
            cin>>d[i];
        }
        for(int i = 0; i < n; ++i)
            cin>>p[i];
        for(int i = 0; i < n; ++i)
            cin>>c[i];
        for(int i = 0; i < n; ++i)
            if(d[i] == 0)
                p[i] *= -1;
        double t = 0;
        double Tc = y/s;
        for(int i = 0; i < n; ++i){
            double front = p[i], back = p[i] - c[i];
            if(front + v[i]*(t + Tc) + MIN_DIST < 0){
                t = t + Tc;
                continue;
            }
            if(back + v[i]*t - MIN_DIST >  0){
                t = t + Tc;
                continue;
            }
            double TT = (-back/v[i]) + MIN_DIST;
            t = TT + Tc;
        }
        cout<<t<<'\n';
    }
    return 0;
}
