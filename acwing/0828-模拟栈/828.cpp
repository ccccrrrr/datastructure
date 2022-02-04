#include <bits/stdc++.h>
using namespace std;
string s;
int x;
const int N = 1000001;
int idx=-1;
int st[N];
int M;
int main() {
    ios::sync_with_stdio(false);
    cin >> M;
    while(M--) {
        cin >> s;
        if(s == "push") {
            cin >> x;
            st[++idx]=x;
        } else if(s == "query") {
            cout << st[idx] << endl;
        } else if(s == "pop") {
            --idx;
        } else if(s == "empty") {
            if(idx < 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}