#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;

int Select(vector<int>& vv, int k) {
    if(vv.size() == 1)
        if(k == 1) return vv.at(0);
        else return 0;

    vector<int> S1, S2, S3;
    int l = vv.size();
    vector<int> M;
    for(int i = 0; i < l; ) {
        int last = min(i+5, l);
        sort(vv.begin()+i, vv.begin()+last);
        M.push_back(vv.at((i+last)/2));
        i += 5;
    }
    int ll = M.size() / 2;
    if(ll * 2 != M.size()) ll++;
    int pivot = Select(M, ll);
    for(int i = 0; i < l; i+= 5) {
        if(i + 4 >= l) {
            for(; i < l; i++)
                if(vv.at(i) == pivot) S3.push_back(vv.at(i));
                else if(vv.at(i) < pivot) S1.push_back(vv.at(i));
                else S2.push_back(vv.at(i));
            continue;
        }
        if(vv.at(i+2) < pivot) {
            S1.push_back(vv.at(i));S1.push_back(vv.at(i+1));
            S1.push_back(vv.at(i+2));

            if(vv.at(i+3) < pivot) S1.push_back(vv.at(i+3));
            else if(vv.at(i+3)== pivot) S3.push_back(vv.at(i+3));
            else S2.push_back(vv.at(i+3));

            if(vv.at(i+4) < pivot) S1.push_back(vv.at(i+4));
            else if(vv.at(i+4)==pivot) S3.push_back(vv.at(i+4));
            else S2.push_back(vv.at(i+4));
        } else if (vv.at(i+2) > pivot) {

            S2.push_back(vv.at(i+3));S2.push_back(vv.at(i+4));S2.push_back(vv.at(i+2));

            if(vv.at(i+1) < pivot) S1.push_back(vv.at(i+1));
            else if(vv.at(i+1)== pivot) S3.push_back(vv.at(i+1));
            else S2.push_back(vv.at(i+1));
            if(vv.at(i) < pivot) S1.push_back(vv.at(i));
            else if(vv.at(i)==pivot) S3.push_back(vv.at(i));
            else S2.push_back(vv.at(i));
        } else {
            if(vv.at(i+4) < pivot) S1.push_back(vv.at(i+4));
            else if(vv.at(i+4)== pivot) S3.push_back(vv.at(i+4));
            else S2.push_back(vv.at(i+4));

            if(vv.at(i+3) < pivot) S1.push_back(vv.at(i+3));
            else if(vv.at(i+3)== pivot) S3.push_back(vv.at(i+3));
            else S2.push_back(vv.at(i+3));

            if(vv.at(i+2) < pivot) S1.push_back(vv.at(i+2));
            else if(vv.at(i+2)== pivot) S3.push_back(vv.at(i+2));
            else S2.push_back(vv.at(i+2));

            if(vv.at(i+1) < pivot) S1.push_back(vv.at(i+1));
            else if(vv.at(i+1)== pivot) S3.push_back(vv.at(i+1));
            else S2.push_back(vv.at(i+1));

            if(vv.at(i) < pivot) S1.push_back(vv.at(i));
            else if(vv.at(i)==pivot) S3.push_back(vv.at(i));
            else S2.push_back(vv.at(i));
        }
    }

    if(k <= S1.size())
        return Select(S1, k);
    else if( k <= S1.size() + S3.size()) {
        return pivot;
    } else {
        return Select(S2, k-S1.size() - S3.size());
    }
}

int main(){
    int k;
    scanf("%d %d", &N, &k);
    vector<int> A;
    for(int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        A.push_back(tmp);
    }
    // int S1[1000], S2[1000];
    if(k > A.size()) {
        printf("NO!");
        return 0;
    }
    printf("%d", Select(A, k));
    return 0;
} 