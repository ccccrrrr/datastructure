#include <bits/stdc++.h>
using namespace std;
queue<int> q1,q2;
int a[100001];
int main() {
    int m, n;
    scanf("%d%d",&m,&n);
    int x;
    int ptr = 0;
    int count=0;
    for(int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for(; ptr < n-1; ++ptr) {
        while(!q1.empty()) {
            if(a[q1.front()] >= a[ptr]) q1.pop();
            else break;
        }
        q1.push(ptr);
    }
    for(; ptr < m; ++ptr) {
        while(q1.front() <= ptr-n) q1.pop();
        if(q1.empty()) {
            printf("%d ",a[ptr]);
            q1.push(ptr);
        } else {
            while(!q1.empty()) {
                if(a[q1.front()] >= a[ptr]) {
                    q1.pop();
                } else break;
            }
            q1.push(ptr);
            printf("%d ", a[q1.front()]);
        } 
    }
    return 0;
}