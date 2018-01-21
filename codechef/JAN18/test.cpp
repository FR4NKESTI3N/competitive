#include<iostream>
#include<algorithm>
using namespace std;

int main(void){
    int x[10] = {10,9,8,7,6,5,4,3,2,1};
    partial_sort(x,x+5,x+7);
    for(int a : x)
        cout<<a<<' ';
    cout<<'\n';
}
