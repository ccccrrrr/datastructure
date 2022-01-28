#include <bits/stdc++.h>
using namespace std;
// 数据已加强，取最左侧，最右侧，中间的值都会超时OTZ

void quicksort(int a[], int l, int r) {
    if(l >= r) return;
    int idx = rand() % (r-l+1) + l;
    swap(a[l], a[idx]);
    int x = a[l], i = l-1, j = r+1;
    while(i<j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i<j) swap(a[i], a[j]);
    }
    quicksort(a, l, j);
    quicksort(a, j+1, r);
}

const int N = 100001;
int a[N];
int main() {
    // freopen("in", "r", stdin);
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n-1);
    for(int i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }
    return 0;
}