#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int M, val[N], nxt[N], head, idx;
int seq[N];
int main() {
    char c;
    int x, k;
    scanf("%d\n", &M);
    while(M--) {
        scanf("%c\n", &c);
        switch(c) {
            case 'H':
            scanf("%d\n", &x);
            // printf("insert node in head: %d, now is head->%d -> %d -> %d\n", idx+1, idx+1,head,nxt[head]);
                nxt[++idx]=head;
                val[idx] = x;
                head=idx;
                break;
            case 'D':
                scanf("%d\n", &k);
                if(k > 0) {
                    // printf("delete node: %d\n", nxt[k]);
                    nxt[k] = nxt[nxt[k]];
                } else {
                    // printf("delete head: %d, and change to %d\n", head, nxt[head]);

                    head = nxt[head];
                }
                break;
            case 'I':
                scanf("%d %d\n", &k,&x);
                // printf("insert node after: %d, now is %d -> %d -> %d\n", k, k, idx, nxt[k]);
                val[++idx]=x;
                nxt[idx]=nxt[k],nxt[k]=idx;
                break;
        }
    }
    while(head != 0) {
        printf("%d ", val[head]);
        head = nxt[head];
    }
    
    return 0;
}