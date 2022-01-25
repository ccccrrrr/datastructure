#include <bits/stdc++.h>
using namespace std;

void print(int a[], int length) {
    for(int i = 0; i < length; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void quicksort(int a[], int l, int r, int length) {
    if(l >= r) return;
    int x = a[l], i = l-1, j = r+1;
    while(i < j) {
        do i++; while(a[i] < x);
        do j--; while(a[j] > x);
        if(i < j) swap(a[i],a[j]);
    }
    print(a, length);
    quicksort(a, l, j, length);
    quicksort(a, j+1, r, length);
}

int main() {
    int a[] = {5,2,3,6,8,1,3,0};
    quicksort(a, 0, 7, 8);
}