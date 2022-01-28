#include <bits/stdc++.h>
using namespace std;
int a[100001] = {0};
int n;
int cnt[100001];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int res = 0;
    int l = 0, r = 0;
    for(; r < n; ++r){
        cnt[a[r]]++;
        while(cnt[a[r]] > 1) {
            cnt[a[l]]--;
            l++;
        }
        res = max(res, r-l+1);
        
    }
    printf("%d", res);
}