#include <cstdio>
#include <iostream>
using namespace std;

int a[100001];
int N;
int M;
int rooty = 0;
int rootz = 0;

int FindRoot(int x) {
    int p = x;
    while(a[p] >= 0) {
        p = a[p];
    }
    int pp = x;
    while(a[pp] >= 0) {
        int temp = a[pp];
        a[pp] = p;
        pp = temp;
    }
    return p;
}

int main() {
    scanf("%d %d", &N, &M);
    for(int i = 0; i < 100001; i++) {
        a[i] = -1;
    }
    for(int i = 0; i < M; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        switch(x) {
        case 1:
            rooty = FindRoot(y);
            rootz = FindRoot(z);
            if(rooty == rootz) {
                // the two has already been the same group, so don't need any operation.
            } else {
                if(a[rooty] < a[rootz]) {
                    a[rootz] += a[rooty];
                    a[rooty] = rootz;
                } else {
                    a[rooty] += a[rootz];
                    a[rootz] = rooty;
                }
            }
            break;
        case 2:
            rooty = FindRoot(y);
            rootz = FindRoot(z);
            if(rooty == rootz && rooty != -1 && rootz != -1) {
                printf("Y\n");
            } else {
                printf("N\n");
            }
            break;
        }
    }
    return 0;
}