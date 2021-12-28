#include <bits/stdc++.h>
using namespace std;
int maxmatrix[2000][2000];
int minmatrix[2000][2000];
int N;
int a[2000];
int cost(int start, int end) {
    int sum = 0;
    for(int i = start; i != end; i = (i+1)%N) {
        sum += a[i];
    }
    sum += a[end];
    return sum;
}
int main(){
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        maxmatrix[i][i] = 0;
        minmatrix[i][i] = 0;
    }
    // [0, 0]
    int l = 0;
    for(int i = 1; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int res = 100000;
            int resmax = 0;
            for(int p = (N+j)%N; p != (i+j+N)%N; p = (p+1) % N) {
                res = min(res, minmatrix[(N+j)%N][(p+N)%N]+minmatrix[(p+1+N)%N][(j+N+i)%N]);
                resmax = max(resmax, maxmatrix[(N+j)%N][(p+N)%N]+maxmatrix[(p+1+N)%N][(j+N+i)%N]);

            }
            minmatrix[(N+j)%N][(j+N+i)%N] = res + cost((N+j)%N, (j+N+i)%N);
            maxmatrix[(N+j)%N][(j+N+i)%N] = resmax + cost((N+j)%N, (j+N+i)%N);
        }
    }
    int minres = 1000000;
    int maxres = 0;
    for(int i = 0; i < N; i++) {
        minres = min(minres, minmatrix[(i+1)%N][(i+N)%N]);
        maxres = max(maxres, maxmatrix[(i+1)%N][(i+N)%N]);
    }
    printf("%d\n%d", minres, maxres);
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         printf("%d ", minmatrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(int i = 0; i < N; i++) {
    //     for(int j = 0; j < N; j++) {
    //         printf("%d ", maxmatrix[i][j]);
    //     }
    //     printf("\n");
    // }
    // return 0;
} 