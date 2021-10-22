#include <bits/stdc++.h>
#include <queue>
using namespace std;

int a[10000];
int n;
int main() {
    priority_queue<int, vector<int>, greater<int>> q;
    int load = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        q.push(tmp);
    }
    while(q.size() > 1) {
        int q1 = q.top();q.pop();
        int q2 = q.top();q.pop();
        load += q1+q2;
        q.push(q1+q2);
    }
    printf("%d", load);
    return 0;

}