#include <bits/stdc++.h>
using namespace std;
int N;
int O;
#define MAX 22000
int in[MAX+1];
int out[MAX+1];
int cnt = 0;
int c[MAX+1];
char hasApple[MAX+1];
int lowbit[MAX+1];
vector<vector<int>> e(MAX);
char visited[MAX+1];
// 通过dfs可以知道所有子树的范围...
void dfs(int start) {
    in[start] = ++cnt;
    for(auto i : e[start]) {
            dfs(i);
    }
    out[start] = ++cnt;
}

void Update(int idx, int v) {
    while(idx <= N) {
        c[idx] += v;
        idx += lowbit[idx];
    }
}

int getsum(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += c[idx];
        idx -= lowbit[idx];
    }
    return sum;
}

int main() {
    scanf("%d", &N);
    int u, v;
    for(int i = 0; i < N-1; i++) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
    }
    dfs(1);
    scanf("%d", &O);
    for(int i = 1; i <= N; i++)
        hasApple[i] = 1;
    for(int i = 1; i <= cnt; i++) {
        lowbit[i] = i&(-i);
        printf("%d %d\n", i&(-i), i&(i^(i-1)));
        c[i] = lowbit[i];
    }
    for(int i = 0;i < O; i++) {
        char c[20]; int idx;
        scanf("%s%d", c, &idx);
        switch (c[0]) {
        case 'Q':
            printf("%d\n", (getsum(out[idx])-getsum(in[idx]))/2+hasApple[idx]);
            break;
        case 'C':
        if(hasApple[idx]) {
                Update(in[idx], -1);
                Update(out[idx], -1);
                hasApple[idx] = 0;
            } else {
                Update(in[idx], 1);
                Update(out[idx], 1);
                hasApple[idx] = 1;
            }
            break;
        }
    }

    return 0;
}