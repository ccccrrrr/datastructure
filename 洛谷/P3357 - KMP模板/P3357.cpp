#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

string s1, s2;
vector<int> nxt1;
int nxt2[500000];
int ptr = 1;
void get_next(string& s, int nxt[]) {
    int now = 0;
    int x = 1;
    nxt[0] = 0;
    int ss = s.size();
    for(; x < ss;) {
        if(s[now] == s[x]) {
            now++;x++;
            nxt[ptr++] = now;
        } else {
            if(now == 0) {
                x++;nxt[ptr++] = 0;
            } else {
                now = nxt[now-1];
            }
        }
    }
}

void KMP(int nxt[]) {
    int pos = 0, tar = 0;
    int ss = s1.size();
    for(; pos < ss;) {
        if(s1[pos] == s2[tar]) {
            pos++;tar++;
        } else {
            // 不相等的话
            if(tar != 0) {
                tar = nxt[tar-1];
            } else {
                pos++;
            }
        }
        if(tar == s2.size()) {
            printf("%d\n", pos-tar+1);
            tar = nxt[tar-1];
        }
    }
}

void print_next(int nxt[]) {
    for(int i = 0; i < ptr; i++) {
        printf("%d ", nxt[i]);
    }
}

int main() {
    freopen("P3375_1.in", "r", stdin);
    cin >> s1;
    cin >> s2;

    get_next(s2, nxt2);

    KMP(nxt2);

    print_next(nxt2);

    return 0;
}