#include <bits/stdc++.h>
using namespace std;

void divide(vector<int>& A, int b) {
    vector<int> C;
    int r = 0;
    int t = 0;
    for(int i = 0; i < A.size(); ++i) {
        t = t * 10 + A[i];
        if(t >= b) {
            C.push_back(t / b);
            t = t % b;
        } else
            C.push_back(0);
    }
    int idx = 0;
    while(idx < C.size() && C[idx] == 0) idx++;
    if(idx == C.size()) {
        printf("0\n%d", t);
        return;
    } else {
        for(; idx < C.size(); ++idx) printf("%d", C[idx]);
    }
    printf("\n%d", t);
}

int main() {
    string a;
    cin >> a;
    vector<int> A;
    for(int i = 0; i < a.size(); ++i) A.push_back(a[i]-'0');
    int b;
    scanf("%d", &b);
    divide(A, b);
    return 0;
}