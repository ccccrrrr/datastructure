#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int>& A, vector<int>& B) {
    while(A.size() > 1 && A[A.size()-1] == 0) A.pop_back();
    while(B.size() > 1 && B[B.size()-1] == 0) B.pop_back();
    if(A.size() != B.size()) {
        return A.size() > B.size();
    } else {
        int idx = A.size()-1;
        while(idx >= 0 && A[idx] == B[idx]) idx--;
        if(idx >= 0) return A[idx] > B[idx];
        else return true;
    }
}

vector<int> sub(vector<int>& A, vector<int>& B) {
    int t = 0;
    vector<int> C;
    int idx = 0;
    for(; idx < B.size() && idx < A.size(); ++idx) {
        C.push_back((A[idx]-B[idx]-t+10)%10);
        if(A[idx]-B[idx]-t < 0) t = 1;
        else t = 0;
    }
    for(;idx<A.size(); ++idx) {
        C.push_back((A[idx]-t+10)%10);
        if(A[idx]-t<0) t = 1;
        else t=0;
    }
    while(C.size() > 1 && C[C.size()-1] == 0) C.pop_back();
    return C;
}

int main() {
    string a, b;
    cin >> a;
    cin >> b;
    vector<int> A, B;
    for(int i = a.size()-1; i >= 0; --i) A.push_back(a[i]-'0');
    for(int i = b.size()-1; i >= 0; --i) B.push_back(b[i]-'0');
    vector<int> C;
    if(compare(A, B)) C = sub(A, B);
    else {C = sub(B, A);printf("-");}
    for(int i = C.size()-1; i >= 0; --i) printf("%d", C[i]);
    return 0;
}