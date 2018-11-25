#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef pair<int, int> pii;

int valid(int x, int y, int m, int n){
    return((x < m && y < n) && (x >= 0 && y >= 0));
}
//you may add more methods here

int minHops(int mat[64][64], int m, int n){
    queue<pair<int, pii>> q;
    q.push(make_pair(1, pii(0, 0)));
    while(!q.empty()){
        int i = q.front().second.first,
            j = q.front().second.second;
        int cells = q.front().first;
        // cout << i << ' ' << j << '\n';
        q.pop();
        if(i == m - 1 && j== n - 1)
            return cells;
        int x = mat[i][j];
        if(valid(i + x, j, m, n))
            q.push(make_pair(cells + 1, pii(i + x, j)));
        if(valid(i, j + x, m, n))
            q.push(make_pair(cells + 1, pii(i, j + x)));
    }
    return 0;
}


int main () {
    int testCases, rows, cols;
    int arr[64][64];
    int i, j, k;
    int result;

    scanf("%d",&testCases);
    for (i = 0; i < testCases; i++)
    {
        scanf("%d %d",&rows,&cols);

        for (j = 0; j < rows; j++)
            for (k = 0; k < cols; k++)
                scanf("%d",&arr[j][k]);

        result = minHops(arr,rows,cols);
        printf("%d\n",result);
    }
    return 0 ;
}
