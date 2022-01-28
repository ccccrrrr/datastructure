#include <bits/stdc++.h>
using namespace std;

vector<int> mul(vector<int>& A, int b) {
    int t = 0;
    vector<int> C;
    for(int i = 0; i < A.size(); ++i) {
        C.push_back((A[i]*b+t)%10);
        t = (A[i]*b+t)/10;
    }
    while(t > 0) {
        C.push_back(t%10);
        t /= 10;
    }
    while(C.size()>1 && C[C.size()-1] == 0) C.pop_back();
    return C;
}

int main() {
    vector<int> A;
    string a;
    cin >> a;
    int b;
    scanf("%d", &b);
    for(int i = a.size()-1; i >= 0; --i) A.push_back(a[i]-'0');
    vector<int> C = mul(A, b);
    for(int i = C.size()-1; i >= 0; --i) printf("%d", C[i]);
    return 0;
}