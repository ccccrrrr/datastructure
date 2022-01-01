#include <bits/stdc++.h>
/**
 * 读入N，为节点个数
 * 读入N-1条边，每次读入一个出节点时都说明该节点不会是根节点
 * 创建一个count数组，如果最近父节点是idx，那么count[idx]++即可
 * 每次读入
 * 最后读count数组数据，如果不为0就输出count[idx]的值
 * 
 * LCA算法：
 * 1.首先使用dfs求出每个节点的深度和其上2^i(i=0,1,2,...)层的祖先
 * 2.求两节点LCA时，首先保持两节点的深度统一，如果两节点上的$2^i$层的祖先不相同，那两节点就向上走$2^i$层
 * 循环结束后任一节点的父节点就是两节点的LCA
 */
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
    // 注意题目中已经说了会有非常多组数据输入，必须在最外层套个while...不然直接WA
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