#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 901
long long int N=0;
char not_root[901];
struct Edge {
    int u, v, next;
};
Edge edge[MAX_SIZE];
int cnt = 0;
int head[MAX_SIZE]={0};
int root=0;
long long int _count[901] = {0};
void add_edge(int u, int v) {
    edge[cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
long long int depth[MAX_SIZE];
long long int fa[901][32];
// root: 当前节点 parent: 父亲节点
void dfs(int root, int parent) {
    fa[root][0] = parent;

    depth[root] = depth[parent]+1;

    for(int i = 1; i < 31; ++i) {
        fa[root][i] = fa[fa[root][i-1]][i-1];
    }
    for(int i = head[root]; ~i; i = edge[i].next) {
        dfs(edge[i].v, root);
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    int tmp = depth[u] - depth[v];
    for(int j = 0; tmp; ++j, tmp >>= 1) {
        if(tmp & 1) u = fa[u][j];
    }
    if(u == v) return u;
    for(int j = 31; j >= 0 && u != v; j--) {
        if(fa[u][j] != fa[v][j]) {
            u = fa[u][j];
            v = fa[v][j];
        }
    }
    return fa[u][0];
}
// 实在不知道哪里错了...
int main() {
    while(scanf("%lld", &N) != EOF) {
    int a, b, c;
    memset(head, -1, sizeof(head));
    memset(not_root, 0, sizeof(not_root));
    memset(_count, 0, sizeof(_count));
    cnt = 0;
    root = 0;
    for(long long int i = 0; i < N; i++) {
        scanf("%d:(%d)", &a, &b);
        for(int j = 0; j < b; j++) {
            scanf(" %d", &c);
            not_root[c] = 1;
            add_edge(a, c);
        }
    }
    for(int i = 1; i <= N; i++)
        if(not_root[i] == 0) {
            root = i;
            break;
        }
    dfs(root, 0);
    long long int times;
    scanf("%lld", &times);
    for(long long int i = 0; i < times; i++) {
        while(getchar() != '(');
        scanf("%d%d", &b, &c);
        while(getchar() != ')');
        _count[LCA(b, c)]++;
    }
    for(int i = 1; i <= N; i++) {
        if(_count[i] != 0) {
            printf("%d:%lld\n", i, _count[i]);
        }
    }
    }
    return 0;
}