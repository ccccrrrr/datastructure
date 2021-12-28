#include<bits/stdc++.h>
using namespace std;
const int inf=2139062143;
const int maxn=1000;
const int maxm=80000;
int m,n,s,t,nf,nc,tc;
int a,b,c;
#define S 1
int matrix[10000][10000] = {0};
vector<vector<int>> v(10000);
void add(int m,int n,int cap){
    v[m].push_back(n);
    v[n].push_back(m);
    if(cap == -1) {
        matrix[m][n] = -1;
        matrix[n][m] = -1;
    }
    matrix[m][n] = cap;
    matrix[n][m] = 0;
}

long long la,lb;

bool dfs(vector<int>& path, vector<char>& visited, int from, int T) {
    printf("start bfs. from: %d\n", from);
    if(!path.empty() && from == T) {
        return true;
    }
    for(auto e : v[from]) {
        if(visited[e] == 1) continue;
        if(matrix[from][e] == 0) continue;
        visited[e] = 1;
        path.push_back(e);
        if(dfs(path, visited, e, T)) return true;
        path.pop_back();
        visited[e] = 0;
    }
    return false;
}
int FF(int T) {

    vector<int> path;
    vector<char> visited(10000, 0);

    int res = 0;
    visited[S] = 1;
    while(dfs(path, visited, S, T)) {
        printf("find one:\n");
        int from = 0; int to = 0;
        for(auto e : path) {
            to = e;
            printf("(%d, %d)  -  ", from, to);
            from = to;
        }
        printf("\n");
        int maxcost = 501;
        from = S;
        to = 0;
        for(auto e : path) {
            // if(e == path[0])
                // continue;
            to = e;
            // printf("from: %d to: %d\n", from, to);
            if(matrix[from][to] != -1)
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
            if(matrix[from][to] != -1) {
            matrix[from][to] -= maxcost;
            matrix[to][from] += maxcost;
            }
            from = to;
        }

        for(int i = 1; i < 10000; i++)
            visited.at(i) = 0;
        path.clear();
    }
    return res;
}

int main(){
    scanf("%d%d",&m,&n);
    s=0,t=n*m+n+1;
    for(int i=1;i<=n;i++) add(s,i,1);
    for(int i=n+1;i<=n*m+n;i++) add(i,t,1);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        scanf("%d",&a);
        for(int k=1;k<=n;k++) add(i,n*j+k,a*k);
    }
    tc = FF(t);
    printf("%.2lf\n",1.0*tc/n);
    return 0;
}