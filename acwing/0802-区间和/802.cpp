#include <bits/stdc++.h>
using namespace std;

int a[300003],s[300003];

vector<int> all;
vector<pair<int,int>> add, query;

int find(int val) {
    // printf("find: %d\n", val);
    int l = 0, r = all.size()-1;
    int mid = (l+r)/2;
    while(l < r) {
        if(all[mid] >= val) {
            r = mid;
        } else l = mid+1;
        mid = (l+r)/2;
    }
    // printf("r: %d\n", r);
    return r+1;
}

int main() {
    int n, m, x, c, l, r;
    scanf("%d%d", &n,&m);
    for(int i = 0;i < n; ++i) {
        scanf("%d%d", &x, &c);
        add.push_back({x,c});
        all.push_back(x);
    }
    while(m--) {
        scanf("%d%d", &l, &r);
        query.push_back({l,r});
        all.push_back(l);all.push_back(r);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    for(auto p : add) {
        int pointer = find(p.first);
        a[pointer] += p.second;
    }
    for(unsigned int i = 1; i <= all.size(); ++i) s[i]=s[i-1]+a[i];
    for(auto q : query) {
        int p1 = find(q.first);
        int p2 = find(q.second);
        printf("%d\n", s[p2]-s[p1-1]);
    }
        
    return 0;
    
}