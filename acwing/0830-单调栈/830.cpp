#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
stack<int> s;
int a[N];
int n;
int main() {
    scanf("%d", &n);
    int val;
    for(int i = 0;i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; ++i) {
        while(!s.empty() && s.top() >= a[i]) s.pop();
        if(s.empty()) printf("-1 ");
        else printf("%d ", s.top());
        s.push(a[i]);
    }
}