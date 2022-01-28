#include <bits/stdc++.h>
using namespace std;
int a[100001], b[100001];

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    for(int i = 0; i < x; ++i) scanf("%d", &a[i]);
    for(int i = 0; i < y; ++i) scanf("%d", &b[i]);
    int t=0,g=0;
    while(true) {
        while(g < y && a[t]!=b[g]) g++;
        if(g >= y) {
            printf("No");
            return 0;
        }
        g++;t++;
        if(t >= x) {
            printf("Yes");
            return 0;
        }
    }
}