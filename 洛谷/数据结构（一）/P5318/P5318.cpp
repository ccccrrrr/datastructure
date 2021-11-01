#include <bits/stdc++.h>
#include <functional>

using namespace std;

#define N 100001
int n, m;
vector<int> edges[N];
int cnt;
void add(int a, int b) {
    edges[a].push_back(b);
}
void dfs(int root) {
    stack<int> s;
    bool visited[N] = {false};
    s.push(root);
    visited[root] = true;
    while(!s.empty()) {
        int tmp = s.top();
        s.pop();
        printf("%d ", tmp);
        for(auto i = edges[tmp].begin(); i != edges[tmp].end(); i++) {
            if(visited[*i] == false) {
                visited[*i] = true;
                s.push(*i);
            }
        }
    }
}
void bfs(int root) {
    queue<int> q;
    bool visited[N] = {false};
    q.push(root);
    visited[root] = true;
    while(!q.empty()) {
        int tmp = q.front();
        printf("%d ", tmp);
        q.pop();
        for(auto i : edges[tmp]) {
            if(visited[i] == false) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
    }
    for(int i = 0; i < n; i++) {
        sort(edges[i].begin(), edges[i].end(), greater_equal<int>());
    }
    dfs(1);
    printf("\n");
    for(int i = 0; i < n; i++) {
        reverse(edges[i].begin(), edges[i].end());
    }
    bfs(1);
}