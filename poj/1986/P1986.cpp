#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 50001
struct Edge {
    int v, w, next;
};
Edge e[MAX_SIZE];
int cnt;
int head[MAX_SIZE];
int N, M, K;
char visited[MAX_SIZE];
int dep[MAX_SIZE];
int fa[MAX_SIZE][32];
int distance[MAX_SIZE][32];

void add_edge(int u, int v, int distance) {
    e[cnt].v = v;e[cnt].w = distance;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int root, int parent) {
    dep[root] = dep[parent] + 1;

    fa[root][0] = parent;
    distance[root][0] = 

    for(int i = 1; i < 32; i++) {
        fa[root][i] = fa[fa[root][i-1]][i-1];
        distance
    }


}

long long int LCA(int u, int v) {

}

// 四个方向似乎对这题并没有什么影响...
int main() {
    scanf("%d %d", &N, &M);
    int a, b, c;
    char d;
    for(int i = 0; i < M; i++) {
        scanf("%d %d %d %c", &a, &b, &c, &d);
        add_edge(a, b, c);
        add_edge(b, a, c);
    }
    dfs(1, 0);
    scanf("%d", &K);
    for(int i = 0; i < K; i++) {
        scanf("%d %d", &a, &b);
        printf("%lld", LCA(a, b));
    }
    return 0;
}