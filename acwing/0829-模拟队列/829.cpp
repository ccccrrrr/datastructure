#include <bits/stdc++.h>
using namespace std;
int q[100003];
int l,r;
string op;
int main() {
    int x,n;
    scanf("%d", &n);
    while(n--) {
        cin >> op;
        if(op == "push") {
            scanf("%d\n", &x);
            q[++r]=x;
        } else if(op == "empty") {
            if(l == r) printf("YES\n");
            else printf("NO\n");
        } else if(op == "pop") {
            ++l;
        } else if(op == "query") {
            printf("%d\n",q[l+1]);
        }
    }
}