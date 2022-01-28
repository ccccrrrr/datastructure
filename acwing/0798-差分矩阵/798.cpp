#include <bits/stdc++.h>
using namespace std;
    int a[1001][1001] = {0};
    int b[1001][1001] = {0}; // 注意，n <= 1000，开大了可能会Memory Limit Exceed
int main() {
    int n, m, q;
    scanf("%d%d%d", &n,&m, &q);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    }
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j < m; ++j) {
            b[i][j] += a[i][j];
            b[i][j+1] -= a[i][j];
            b[i+1][j] -= a[i][j];
            b[i+1][j+1] += a[i][j];
        }
    }
    for(int i = 1; i < n; ++i) {
        b[i][m] += a[i][m];
        b[i+1][m] -= a[i][m];
    }
    for(int i = 1; i < m; ++i) {
        b[n][i] += a[n][i];
        b[n][i+1] -= a[n][i];
    }
    b[n][m] += a[n][m];
    while(q--) {
        int x1,y1,x2,y2,c;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &c);
        b[x1][y1] += c;
        if(x2 < n) b[x2+1][y1] -= c;
        if(y2 < m) b[x1][y2+1] -= c;
        if(x2 < n && y2 < m) b[x2+1][y2+1] += c;
    }
    a[1][1]=b[1][1];
    for(int i = 2; i <= m;++i) {
        a[1][i] = a[1][i-1]+b[1][i];
    }
    for(int i = 2; i <= n; ++i) {
        a[i][1] = a[i-1][1]+b[i][1];
        for(int j = 2; j <= m; ++j) {
            a[i][j] = a[i-1][j]+a[i][j-1]-a[i-1][j-1]+b[i][j];
        }
    }
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}