#include <iostream>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int a[500001];
int b[500001];
int n;
long long int mysort(int a[],int left, int right) {
    if(left >= right) {
        return 0;
    }
    if(left + 1 == right) {
        if(a[left] > a[right]) {
            swap(a[left], a[right]);
            return 1;
        } else {
            return 0;
        }
    }
    int middle = (left + right) / 2;
    long long int ll = mysort(a, left, middle);
    long long int rr = mysort(a, middle+1, right);
    int lptr = left;
    int rptr = middle+1;
    int ptr = left;
    long long int count=0;
    while(lptr <= middle && rptr <= right) {
        if(a[lptr] <= a[rptr]) {
            b[ptr] = a[lptr];
            ptr++;lptr++;
        } else {
            b[ptr] = a[rptr];
            count += (long long int)(middle - lptr + 1);
            ptr++;rptr++;
        }
    }
    while(lptr <= middle) b[ptr++] = a[lptr++];
    while(rptr <= right) b[ptr++] = a[rptr++];
    memcpy(a + left, b + left, sizeof(int) * (right-left+1));
    return count + ll + rr;
}
int main() {
    scanf("%d", &n);
    for(int i = 0;i < n; i++) {
        scanf("%d", &a[i]);
    }
    long long int count = mysort(a, 0, n-1);
    printf("%lld", count);
}