#include <bits/stdc++.h>
#include <forward_list>
#include <iostream>
using namespace std;
int N, M;
#define MAX_EDGE 400010
#define T 1001
#define S 0

int matrix[1002][1002];
vector<vector<int>> edges(1002);

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
// Edge * edges[MAX_EDGE];
map<int, vector<Edge*>> m;
int idx = 0;

void addEdge(int u, int v, int cap) {
    // edges[idx] = new Edge(idx, u, v, cap, 0);
    // m[v].push_back(edges[idx]);
    // m[u].push_back(edges[idx++]);
    matrix[u][v] = cap;
    matrix[v][u] = 0;
    edges[u].push_back(v);
    edges[v].push_back(u);
}

bool bfs(int from) {
    queue<int> q;
    q.push(from);
    vector<bool> visited(2000, false);
    visited[from] = true;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        vector<Edge*> s = m[node];
        for(auto ss : s) {
            if(ss->from == node && (visited[ss->to] == 1 || ss->cap <= 0)) continue;
            if(ss->to == node && (visited[ss->from] == 1 || ss->f <= 0)) continue;
            int to = 0;
            if(ss->from == node) to = ss->to;
            else to = ss->from;
            visited[to] = true;
            q.push(to); 
        }
    }
    return visited[T];
}


bool dfs(vector<int>& path, vector<char>& visited, int from) {
    // printf("start bfs. from: %d\n", from);
    if(!path.empty() && from == T) {
        return true;
    }
    for(auto e : edges[from]) {
        if(visited[e] == 1) continue;
        if(matrix[from][e] <= 0) continue;
        visited[e] = 1;
        path.push_back(e);
        if(dfs(path, visited, e)) return true;
        path.pop_back();
        visited[e] = 0;
    }
    return false;
}

int FF() {

    // vector<Edge*> path;
    vector<int> path;
    vector<char> visited(1002, 0);

    int res = 0;
    int count = 0;
    visited[S] = 1;
    while(dfs(path, visited, S)) {
        count++;
        // printf("find one:\n");
        // for(auto e : path) {
            // printf("(%d, %d)  -  ", e->from, e->to);
        // }
        // printf("\n");
        int maxcost = 501;
        int from = S;
        int to = 0;
        for(auto e : path) {
            // if(e == path[0])
                // continue;
            to = e;
            // printf("from: %d to: %d\n", from, to);
            maxcost = min(maxcost, matrix[from][to]);
            from = to;
        }
        // printf("max cost: %d\n", maxcost);
        res += maxcost;
        from = S;
        for(auto e : path) {
            // if(e == path[0])
                // continue;
            to = e;
            matrix[from][to] -= maxcost;
            matrix[to][from] += maxcost;
            from = to;
        }

        for(int i = 1; i < 1002; i++)
            visited.at(i) = 0;
        path.clear();
    }
    return res;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 1002; i++) 
        for(int j = 0; j < 1002; j++)
            matrix[i][j] = -1;
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