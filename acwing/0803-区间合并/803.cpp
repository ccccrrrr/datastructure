#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> t;

int main() {
    int n;
    scanf("%d", &n);
    int x,y;
    while(n--) {
        scanf("%d%d", &x, &y);
        t.push_back({x,y});
    }
    sort(t.begin(),t.end());
    int l = -1e9-1, r=-1e9-1;
    int res = 0;
    for(auto p : t) {
        if(p.first > r) {
            res++;
            l = p.first;r=p.second;
        } else {
            r = max(r, p.second);
        }
    }
    printf("%d", res);
    return 0;
}