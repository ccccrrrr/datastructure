#include <bits/stdc++.h>
using namespace std;

// 找到左边那个
int b1_search(int a[], int l, int r, int x) {
    int middle = (l + r) >> 1;
    while(l < r) {
        if(a[middle] >= x) r = middle; // 收紧右边界，找到最左值
        else l = middle+1; 
        middle = (l+r)>>1;
    }
    if(a[l] == x) return l;
    else return -1;
}

// 找到右边那个
int b2_search(int a[], int l, int r, int x) {
    int middle = (l + r + 1) >> 1;
    while(l < r) {
        if(a[middle] <= x) l = middle; // 应该收紧的是左边界，才能找到最右值
        else r = middle - 1;
        middle=(l+r+1)>>1;
    }
    return l;
}

const int N = 100001;
int a[N];
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i = 0; i < m; ++i) scanf("%d", &a[i]);
    int x;
    while(n--) {
        scanf("%d", &x);
        int res = b1_search(a, 0, m-1, x);
        if(res == -1) printf("-1 -1\n");
        else {
            printf("%d %d\n", res, b2_search(a, 0, m-1, x));
        }
    }
    return 0;
}