#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int _forward[N],nxt[N],val[N],head,tail,idx=2;
int x,k;
int m;
string op;

void init() {
    head = 1;tail=2;
    _forward[2]=1,nxt[1]=2;
}

void insert_left(int x) {
    val[++idx] = x;
    nxt[idx]=nxt[1];
    nxt[1]=idx;
    _forward[nxt[idx]]=idx;
    _forward[idx]=1;
}


void insert_right(int x) {
    val[++idx]=x;
    nxt[idx]=2;
    nxt[_forward[2]]=idx;
    _forward[idx]=_forward[2];
    _forward[2]=idx;
}

void delete_k(int k) {
    // printf("prev value: %d, idx: %d, nxt value: %d, idx: %d\n", val[_forward[k]], _forward[k], val[nxt[k]], nxt[k]);
    nxt[_forward[k]]=nxt[k];
    _forward[nxt[k]]=_forward[k];
}


void __insert_left(int k, int x) {
    val[++idx]=x;
    nxt[idx]=k;
    nxt[_forward[k]]=idx;
    _forward[idx]=_forward[k];
    _forward[k]=idx;
}

void __insert_right(int k, int x) {
    val[++idx]=x;
    nxt[idx]=nxt[k];
    _forward[idx]=k;
    _forward[nxt[k]]=idx;
    nxt[k]=idx;
}

void print_whole() {
    int h = 1;
    h = nxt[h];
    while(h != 2) {
        printf("%d ", val[h]);
        h = nxt[h];
    }
    printf("\n");
}

int main() {
    ios::sync_with_stdio(false);
    cin >> m;
    init();
    while(m--) {
        cin >> op;
        if(op == "L") {
            cin >> x;
            insert_left(x);
            // print_whole();
        } else if(op == "R") {
            cin >> x;
            insert_right(x);
            // print_whole();
        } else if(op == "D") {
            cin >> k;
            delete_k(k+2);
            // print_whole();
        } else if(op == "IL") {
            cin >> k >> x;
            __insert_left(k+2,x);
            // print_whole();
        } else if(op == "IR") {
            cin >> k >> x;
            __insert_right(k+2,x);
            // print_whole();
        }
    }
    print_whole();
}