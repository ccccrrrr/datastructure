#include <bits/stdc++.h>
using namespace std;
int n;
// 显然，这还不是最快的额
void cnt(int k) {
    int c=0;
    while(k>0) {
        c += k & 1;
        k >>= 1;
    }
    printf("%d ", c);
}

int main() {
    
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        cnt(x);
    }
    
    return 0;
}