#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
typedef unsigned long long ull;
#define MOD  1000000009
#define p 10000007
ull hh[500000];
ull i;
char s[2000];
bool check[1000000010];
int main() {
    scanf("%lld", &i);
    int num = 0;
    int k;
    while(i--) {
        scanf("%s", s);
        hh[0] = s[0];
        int l = strlen(s);
        k = 1;
        for(; k < l; k++) {
            hh[k] = (((hh[k-1]*p)+s[k]) % MOD);
        }
        k = k == l ? k-1:k;
        if(check[hh[k]] == true) {
        } else {
            num++;
            check[hh[k]] = true;
        }
    }
    printf("%d", num);
    return 0;
}