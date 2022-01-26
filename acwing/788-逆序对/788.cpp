#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int a[N];
int c[N];
long long int result;
void mergesort(int a[], int l, int r) {
    if(l>=r) return;
    int mid = (l+r)>>1;
    mergesort(a, l, mid);
    mergesort(a, mid+1, r);
    int lp=l, rp=mid+1;
    int p = l;
    while(lp <= mid && rp <= r) {
        if(a[lp] <= a[rp]) c[p++]=a[lp++];
        else {
            result += mid-lp+1; // 右半部分的某元素较大，那么左半部分的[lp,mid]元素可以与rp指向的元素形成逆序对
            c[p++]=a[rp++];
        }
    }
    while(lp <= mid) c[p++]=a[lp++];
    while(rp <= r) c[p++]=a[rp++];
    for(int i = l; i <= r; ++i) a[i]=c[i];
}

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
    mergesort(a, 0, n-1);
    // for(int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("%lld", result);
}