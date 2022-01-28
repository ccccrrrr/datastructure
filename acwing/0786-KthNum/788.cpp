#include <bits/stdc++.h>
using namespace std;
int k;
const int N = 100001;
int a[N];
int n;

int quicksort(int a[], int l, int r, int k) {
    if(l == r && k == 1) return a[l];
    int idx = rand() % (r-l+1)+l;
    swap(a[l], a[idx]);
    int x = a[l], i = l-1, j = r+1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i], a[j]);
    }
    if(j-l+1 >= k) return quicksort(a, l, j, k);
    else return quicksort(a, j+1,r, k-j+l-1);
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%d", quicksort(a, 0, n-1, k));
    return 0;
}