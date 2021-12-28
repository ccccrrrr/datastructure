#include <bits/stdc++.h>

using namespace std;
#define MAX_EDGE_NUM 500000
int R[24];
int S[25];
int T;
int N;


int cnt;
vector<vector<int>> e(N);

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 24; i++) {
            scanf("%d", &R[i]);
        }
        memset(S, 0, sizeof(S));
        scanf("%d", &N);

    }
    return 0;
}