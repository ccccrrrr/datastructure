#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[100002] = {0};
    int first;
    int prev;
    int tmp;
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%d", &first);
    a[1] = 0;
    prev = first;
    for(int i = 2; i <= n; ++i) {
        scanf("%d", &tmp);
        a[i]=tmp-prev;
        prev=tmp;
    }
    while(q--) {
        int k,m,p;
        scanf("%d%d%d", &k, &m, &p);
        a[k] += p;
        a[m+1] -= p;
    }
    prev = first;
    for(int i = 1; i <= n; ++i) {
        printf("%d ", prev+a[i]);
        prev += a[i];
    }
    return 0;
}