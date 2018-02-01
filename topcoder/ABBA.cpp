#include<string>

using namespace std;

class ABBA{
public:
    string canObtain(string given_str, string target_str){
        int cur = target_str.length() - 1;
        while(given_str.length() < target_str.length()){
            if(target_str[cur] == 'A'){
                if(cur == 0)
                    target_str.erase(0,1);
                else{
                    target_str.pop_back();
                    --cur;
                }
            }
            else if(cur == 0){
                if(target_str[cur] == 'B'){
                    target_str.erase(0,1);
                    cur = target_str.length() - 1;
                }
                else{
                    return "Impossible";
                }
            }
            else if(cur == target_str.length() - 1){
                if(target_str[cur] == 'B'){
                    target_str.pop_back();
                    cur = 0;
                }
                else
                    return "Impossible";
            }
        }
        return "Possible";
    }
};
