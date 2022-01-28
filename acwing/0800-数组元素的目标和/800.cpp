#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];
int main() {
    int m, x, y;
    scanf("%d%d%d", &x, &y, &m);
    for(int i = 0; i < x; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < y; ++i) scanf("%d", &b[i]);
    int xx = 0, yy = y-1;
    while(true) {
        int t = a[xx]+b[yy];
        if(t == m) {
            printf("%d %d", xx, yy);
            return 0;
        } else {
            if(t < m) xx++;
            else yy--;
        }
    }
}