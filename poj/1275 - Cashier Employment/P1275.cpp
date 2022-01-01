#include <bits/stdc++.h>
using namespace std;
#define MAX_EDGE_NUM 500000
#define MAX_NUM 500000
#define INF 0x30303030
int R[25];
int t[25];
int T;
int N;
int cnt;
struct Node {
    int u,v, w;
};
Node e[MAX_EDGE_NUM];
void add_edge(int u, int v, int w) {
    e[cnt].u = u;
    e[cnt].v = v;
    e[cnt++].w = w;
}

/*
 * r[0...23]表示每个时刻需要的出纳员数量
 * t[0...23]表示每个时刻应征的申请者数目
 * s[0...23]表示0-i时刻雇佣的出纳员总数，s[-1]=0
 * 由题意得：s[i]-s[i-1] >= 0下一个时刻雇佣出纳员得总数总是比现在这一时刻得高
 * s[i-1]-s[i]>=-t[i] 新雇佣的人员肯定不会超过申请者的数目
 * s[23]-s[-1]>= sum 最少雇佣的人数一定大于等于sum（sum即是要求的值）
 * s[i]-s[j]>= r[i](i>j) i = (j+8)mod 24 在[i,j]时刻的有效工作人员
 * s[i]-s[j]>= r[i]-sum(i<j) i=(j+8)mod 24 在[j,i]时刻的有效工作人员
 * 这样就可以构造一个图，可以通过bellman-ford算法查询该图是否有负权环，如果有，说明没有从1到节点24的最短距离，因此没有结果
 * sum可以从1到N进行遍历，如果没有负权环，说明是有解的。
*/

void build(int sum) {
    cnt = 48;
    for(int j = 1; j <= 24; ++j) {
        int i = (j+8) % 24;

	for(i=1;i<=16;i++) add_edge(i+8,i,-R[i+8]);
	for(i=17;i<=24;i++) add_edge(i-16,i,sum-R[i-16]);
    }
    add_edge(24, 0, -sum);
}

bool bellman_ford() {
    vector<int> d(25, INF);
    d[0] = 0;
    for(int i = 0; i <= 24; i++) {
        for(int j = 0; j < cnt; ++j) {
            if(d[e[j].u]+e[j].w < d[e[j].v]) {
                d[e[j].v] = d[e[j].u]+e[j].w;
            }
        }
    }
    for(int j = 0; j < cnt; ++j) {
        if(d[e[j].u]+e[j].w < d[e[j].v]){
            return false;
        }
    }
    return true;
    
}

int main() {
    scanf("%d", &T);
    while(T--) {
        for(int i = 1; i <= 24; i++) {
            scanf("%d", &R[i]);
        }
        memset(t, 0, sizeof(t));

        scanf("%d", &N);
        int a;
        for(int i = 0; i < N; i++) {
            scanf("%d", &a);
            t[a+1]++;
        }
        cnt = 0;
        for(int i = 1; i <= 24;++i) {
            add_edge(i-1, i, t[i]);
            add_edge(i, i-1, 0);
        }
        bool flag = false;
        for(int i = 1;i <= N;i++) {
            // printf("building...\n");
            build(i);
            if(bellman_ford()) {
                printf("%d\n", i);
                flag = true;
                break;
            }
        }
        if(!flag) printf("No Solution\n");
    }
    return 0;
}