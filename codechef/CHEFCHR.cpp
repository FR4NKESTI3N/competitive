#include<iostream>
#include<string>

using namespace std;

int main(void){
    int t, target = 0;
    target |= (1<<('c' - 'a')) + (1<<('h' - 'a')) + (1<<('e' - 'a')) + (1<<('f' - 'a'));
    cin >> t;
    string s;
    while(t--){
        cin >> s;
        int lovely_count = 0;
        if(s.size() >= 4){
            for(int i = 0; i <= s.size() - 4; ++i){
                int mask = 0;
                for(int j = 0; j < 4; ++j)
                    mask |= (1<<(s[i+j] - 'a'));
                if(mask == target){
                    ++lovely_count;
                }
            }
        }
        if(lovely_count == 0)
            cout<<"normal\n";
        else
            cout<<"lovely "<<lovely_count<<'\n';
    }
    return 0;
}
