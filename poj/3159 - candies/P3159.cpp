#include <bits/stdc++.h>
#include <queue>

using namespace std;
int N, M;
#define MAX_SIZE 30000+1
const int inf=0x3f3f3f3f;
#define MAX_EDGE_NUM 150000+1
int cnt = 0;
int head[MAX_EDGE_NUM];
int stu[MAX_SIZE];
struct Edge {
    int u, v, w, next;
}; 

/*
 * 1.读取同学要求：如果同学x希望同学y得到的糖果不比他多于w，就加入一条有向边(x, y)，权值为w。
 * 2.使用spfa算法，将节点1加入栈中，并遍历起点为1的边，松弛每一个节点，如果需要进行松弛操作，且该边的终点并不在栈中，就把该节点加入栈中。
 * 3.d[N]就是最大值
 */

Edge e[MAX_EDGE_NUM];
int d[MAX_SIZE+1];

void add_edge(int u, int v, int w) {
    e[cnt].u = u;e[cnt].v = v;e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt++;
}

void spfa() {
    /* spfa的基本步骤：
     * 1. 使用先进先出的队列保持松弛节点每次取出队首节点
     * 2. 如果更新了距离，那么还需要把v放入优先队列中
     * 不知道为什么用queue就会有问题，但是用了stack就不会超时...
     */
     stack<int> q;
     q.emplace(1);
     bool in[MAX_SIZE+1] = {false};
     for(int i = 1; i <= N; i++) {
        in[i] = false;
        d[i] = inf;
     }
     d[1] = 0;
     in[1] = true;
     int count[MAX_SIZE] = {0};
    while(!q.empty()) {
        int h = q.top();
        // printf("h: %d\n", h);
        q.pop();in[h] = false;
         for(int i = head[h]; ~i; i = e[i].next) {
             if(d[e[i].v] > d[e[i].u] + e[i].w) {
                 d[e[i].v] = d[e[i].u] + e[i].w;
                 if(!in[e[i].v]) {
                     q.push(e[i].v);
                     in[e[i].v] = true;
                 }
             }
         }
     }
     printf("%d", d[N]);
}

int main() {
    int u, v, w;
    scanf("%d %d", &N, &M);
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= N; i++) {
        d[i] = inf;
    }
    for(int i = 1; i <= M; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
    }
    spfa();
    return 0;
}