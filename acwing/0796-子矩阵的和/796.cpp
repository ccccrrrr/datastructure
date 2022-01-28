#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[1001][1001]={0};
    int b[1001][1001]={0};
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    b[1][1] = a[1][1];
    for(int i = 1; i <= n; ++i) b[i][1] = b[i-1][1] + a[i][1];
    for(int i = 1; i <= m; ++i) b[1][i] = b[1][i-1] + a[1][i];
    for(int i = 2; i <= n; ++i) {
        for(int j = 2; j <= m; ++j) {
            b[i][j] = b[i-1][j] + b[i][j-1] + a[i][j] - b[i-1][j-1];
        }
    }
    while(q--) {
        int i,j,k,h;
        scanf("%d%d%d%d", &i, &j, &k, &h);
        printf("%d\n", b[k][h]-b[i-1][h]-b[k][j-1]+b[i-1][j-1]);
    }
    
    return 0;
}