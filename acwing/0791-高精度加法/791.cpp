#include <bits/stdc++.h>
using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    int t = 0;
    vector<int> C;
    int i = 0;
    for(; i < A.size() && i < B.size(); ++i) {
        C.push_back((A[i]+B[i]+t)%10);
        t = (A[i]+B[i]+t)/10;
    }
    for(; i < A.size(); ++i) {
        C.push_back((A[i]+t)%10);
        t=(A[i]+t)/10;
    }
    for(; i < B.size(); ++i) {
        C.push_back((B[i]+t)%10);
        t=(B[i]+t)/10;
    }
    if(t) C.push_back(t);
    while(C.size()>1 && C[C.size()-1] == 0) C.pop_back();
    return C;
}

int main() {
    vector<int> A, B;
    string a, b;
    cin >> a;
    cin >> b;
    for(int i = a.size()-1; i >= 0; --i) A.push_back(a[i]-'0');
    for(int i = b.size()-1; i >= 0; --i) B.push_back(b[i]-'0');
    vector<int> C = add(A, B);
    for(int i = C.size()-1; i >= 0; --i) printf("%d", C[i]);
    return 0;
}