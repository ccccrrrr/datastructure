#include <bits/stdc++.h>
using namespace std;
int main() {
    double n;
    scanf("%lf", &n);
    bool positive = n > 0;
    if(n == 0.0) {
        printf("0.000000");
        return 0;
    }
    if(!positive) n = -n;
    double l = 0.0, r = 0.0, middle;
    if(n > 1.0f) r = n;
    else r = 1.0;
    middle = (l+r)/2;
    while(abs(r-l)>1e-8) {
        // printf("r: %.9f, l: %.9f, middle: %.9f\n", r, l, middle);
        if(middle*middle*middle > n) {
            r = middle;
        } else if(middle*middle*middle<n) {
            l = middle;
        }
        middle=(l+r)/2;
    }
    if(!positive) printf("-");
    printf("%lf", middle);
    return 0;
}