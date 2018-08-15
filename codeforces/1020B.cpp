#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; ++i)
        cin >> p[i];
    vector<int> visited;
    for(int i = 1; i <= n; ++i){
        visited.assign(1001, 0);
        int j = i;
        visited[j] = 1;
        while(visited[p[j]] != 1){
            j = p[j];
            visited[j] = 1;
        }
        cout << p[j] << ' ';
    }
    cout << '\n';
}
