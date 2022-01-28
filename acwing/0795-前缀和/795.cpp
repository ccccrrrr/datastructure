#include <bits/stdc++.h>
using namespace std;
int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    int a[100001];
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    long long int b[100002] = {0};
    b[1] = a[1];
    for(int i = 2; i <= n; ++i) b[i] = b[i-1]+(long long int)a[i];
    while(m--) {
        int x, y;
        scanf("%d%d", &x,&y);
        printf("%d\n", b[y]-b[x-1]);
    }
    
    return 0;
}