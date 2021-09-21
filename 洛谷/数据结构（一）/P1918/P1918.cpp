#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
pair<int, int> a[100001];
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}
int find(int value, int p) {
    int left = 0;
    int right = p-1;
    int middle = (left+right)/2;
    while(left <= right && left >= 0 && right <= p-1) {
        if(a[middle].second > value) {
            right = middle-1;
            middle = (left+right)/2;
        } else if(a[middle].second < value) {
            left = middle+1;
            middle=(left+right)/2;
        } else {
            return middle;
        }
    }
    if(a[left].second == value) return left;
    if(a[right].second == value) return right;
    return -1;
}


int main() {
    int p;
    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
        int temp;
        scanf("%d", &temp);
        a[i].first = i;
        a[i].second = temp;
    }
    sort(a, a+p, cmp);
    int k = 0;
    scanf("%d", &k);
    for(int i = 0; i < k; i++) {
        int v;
        scanf("%d", &v);
        int res = find(v, p);
        if(res == -1) {
            printf("0\n");
        } else {
        printf("%d\n", a[find(v, p)].first+1);
        }
    }
}