#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int A[2000];
int B[2000];
class Product {
public:
    int A;
    int B;
    int no;
    Product(int A, int B):A(A),B(B),no(A-B) {}
};

bool comp(Product * p1, Product * p2) {
    if(p1->no < 0 && p2->no < 0) {
        return p1->A < p2->A;
    } else if(p1->no > 0 && p2->no > 0) {
        return p1->B > p2->B;
    } else if(p1->no < 0 && p2->no > 0) {
        return true;
    } else if(p1->no > 0 && p2->no < 0) {
        return false;
    } else {
        return p1->A < p2->A;
    }
}

int N;
int main(){
    scanf("%d", &N);
    vector<Product *> vv;
    for(int i = 0 ; i < N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i < N; i++)
        scanf("%d", &B[i]);
    for(int i = 0; i < N; i++)
        vv.push_back(new Product(A[i], B[i]));
    sort(vv.begin(), vv.end(), comp);

    int Afinish = 0;
    int Bfinish = 0;
    int current_time =0;
    for(auto it : vv) {
        Afinish += it->A;
        Bfinish = max(Afinish+it->B, Bfinish+it->B);
    }
    printf("%d", Bfinish);

    return 0;
} 