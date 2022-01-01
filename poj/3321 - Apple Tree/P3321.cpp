#include <bits/stdc++.h>
using namespace std;
/**
 * 将树的结构转化成树状数组的结构
 * 使用dfs对树中的每一个节点进行编号，每访问一次节点，计数cnt++
 * 当第一次遇到该顶点时，记录在in数组中，这个顶点的子节点全部扫描完之后，相当于需要退出该节点，再次记录该节点的值，记录在out数组中
 * 这样我们可以知道，一个节点的子树的的in和out一定在节点的(in ,first)之间。
 * 这样，可以构建一个in和out构成的树状数组，每次更新节点或一个节点区间的值，即更新[in, out]的值
 * 在求一个枝干的总值的时候，要注意结果为[in, out]区间和的一半，因为在dfs时是进入一次，退出一次，占据的区间长度至少为2
 */
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