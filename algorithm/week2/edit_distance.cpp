#include <bits/stdc++.h>
using namespace std;
string a1, a2;
int matrix[501][501];

int main() {
    cin >> a1;
    cin >> a2;
    int m = a1.size(); int n = a2.size();
    for(int i = 0; i <= m; i++)
        matrix[i][0] = i;
    int tmp = 1;
    bool kk = false;
    for(int i = 1; i <= n; i++) {
        // printf("tmp: %d\n", tmp);
        if(a1.at(0) != a2.at(i-1) || kk) 
            matrix[1][i] = tmp++;
        else if(i == 1) {
            matrix[1][i] = 0;
            kk = true;
        } else {
            matrix[1][i] = tmp;
            kk = true;
        }
    }

    for(int i = 2; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(a1.at(i-1) != a2.at(j-1)) {
                matrix[i][j] = 1+min(matrix[i-1][j-1],min(matrix[i][j-1], matrix[i-1][j]));
            } else {
                matrix[i][j] = matrix[i-1][j-1];
            }
        }
    }
    printf("%d", matrix[m][n]);
    return 0;
}