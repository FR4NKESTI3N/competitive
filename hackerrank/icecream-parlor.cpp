#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bSearch(vector<int> ar, int key, int low, int high){
    int mid;
    while(low <= high){
        mid = (low + high)/2;
        if(ar[mid] == key)
            return mid;
        if(ar[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    int t, m, n;
    cin>>t;
    while(t--){
        cin>>m>>n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i)
            cin>>a[i];
        vector<int> ar = a;
        sort(ar.begin(), ar.end());
        for(int i = 0; i < n - 1; ++i){
            int k = m - ar[i], l;
            l = bSearch(ar, k, i + 1, n - 1);
            if(l != -1){
                vector<int> res(2, -1);
                for(int j = 0; j < n; ++j){
                    if(res[0] == -1 && a[j] == ar[i]){
                        res[0] = j;
                        continue;
                    }
                    if(a[j] == ar[l]){
                        res[1] = j;
                    }
                }
                sort(res.begin(), res.end());
                cout<<res[0] + 1<<' '<<res[1] + 1<<'\n';
                break;
            }
        }
    }
    return 0;
}
