#include <bits/stdc++.h>
#include <forward_list>
#include <iostream>
using namespace std;
int N, M;
#define MAX_EDGE 400010
int S, T;

class Edge {
public:
    int no;
    int from;
    int to;
    int cap;
    int f;
    Edge(int no, int from, int to, int cap, int f):no(no), from(from), to(to), cap(cap), f(f) {}
};
// s: 0, t: 1001
Edge * edges[MAX_EDGE];
map<int, vector<Edge*>> m;
int idx = 0;

void addEdge(int u, int v, int cap) {
    edges[idx] = new Edge(idx, u, v, cap, 0);
    m[v].push_back(edges[idx]);
    m[u].push_back(edges[idx++]);
}

bool bfs(vector<Edge*>& path, vector<char>& visited, int from) {
    // printf("start bfs. from: %d\n", from);
    if(!path.empty() && from == T) {
        return true;
    }
    vector<Edge*> edges = m[from];
    for(auto e : edges) {
        int to;
        if(e->from == from && e->cap <= 0) continue;
        if(e->to == from && e->f <= 0) continue;
        if(e->from == from) to = e->to;
        else to = e->from;
        if(visited[to] == 1) continue;
        visited[to] = 1;
        path.push_back(e);
        if(bfs(path, visited, to)) return true;
        path.pop_back();
        visited[to] = 0;
    }
    return false;
}

int FF() {

    vector<Edge*> path;
    vector<char> visited(1002, 0);

    int res = 0;
    while(bfs(path, visited, 0)) {
        // printf("find one:\n");
        // for(auto e : path) {
            // printf("(%d, %d)  -  ", e->from, e->to);
        // }
        // printf("\n");
        visited[S] = 1;
        int maxcost = 501;
        int from = S;
        for(auto e : path) {
            if(e->from == from) {
                from = e->to;
                maxcost = min(maxcost, e->cap);
            } else {
                from = e->from;
                maxcost = min(maxcost, e->f);
            }
        }
        // printf("max cost: %d\n", maxcost);
        res += maxcost;
        from = S;
        for(auto e : path) {
            if(e->from == from) {
                from = e->to;
                e->cap -= maxcost;
                e->f += maxcost;
            } else {
                from = e->from;
                e->f -= maxcost;
                e->cap += maxcost;
            }
        }

        for(int i = 0; i < 1002; i++)
            visited.at(i) = 0;
        path.clear();
    }
    return res;
}

int main() {
    scanf("%d %d %d %d", &N, &M, &S, &T);
    int maxday = 0;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        int p, s, e;
        scanf("%d %d %d", &p, &s, &e);
        sum += p;
        addEdge(S, i+1, p);
        for(int j = 500+s; j <= 500+e; j++) {
            // 节点(i+1)到可以工作的每一天
            addEdge(i+1, j, 1);
        }
    }
    for(int i = 500+1; i <= 1000; i++) {
        // 每一天到t的流量最大值都为M
        addEdge(i, 1001, M);
    }

    int res = FF();
    // printf("res: %d\n", res);
    // printf("sum: %d\n", sum);
    if(res == sum)
        printf("Yes");
    else
        printf("No");
    return 0;
}