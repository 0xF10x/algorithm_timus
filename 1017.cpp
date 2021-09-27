#include <iostream>

using namespace std;

long long stairs[501][501];

int main(){
    int n;
    cin >> n;
    for (int x = 0; x <= n; x++)
        stairs[x][0] = 1;
    for (int x = 1; x <= n; x++){
        for (int y = 1; y <= n; y++){
            if (x <= y) {
                stairs[x][y] = stairs[x - 1][y] + stairs[x - 1][y - x];
            }
            else stairs[x][y] = stairs[y][y];
        }    
    } 
    cout << stairs[n - 1][n];
    return 0;
}