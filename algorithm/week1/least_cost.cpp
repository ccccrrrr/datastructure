//
// Created by ZHT on 2021/11/17.
//
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int N;
int x[20000];
int y[20000];
int parent[20000];

class Edge {
public:
    int X1;int Y1;
    int X2;int Y2;
    int A, B;
    int L;
    double length;
    Edge(int A, int B, int X1, int Y1, int X2, int Y2) {
        this->A = A;this->B = B;
        this->X1 = X1;this->Y1 = Y1;this->X2 = X2;this->Y2 = Y2;
        this->L = (X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2);
        this->length = sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
    }

};

int FindParent(int x) {
    while(parent[x] != -1) {
        x = parent[x];
    }
    return x;
}

bool comp(const Edge* e1, const Edge* e2) {
    return e1->length <= e2->length;
}

int main(){
    scanf("%d", &N);
    vector<Edge*> vv;
    for(int i = 0; i < N; i++){
        scanf("%d %d", &x[i], &y[i]);
        parent[i] = -1;
    }
    for(int i = 0; i < N; i ++) {
        for (int j = i; j < N; j++) {
            if (i != j) {
                auto edge = new Edge(i, j,x[i],y[i], x[j], y[j]);
                if(edge->L >= 100 && edge->L <= 1000000)
                    vv.push_back(new Edge(i, j,x[i],y[i], x[j], y[j]));
            }
        }
    }
    double cost = 0;
    sort(vv.begin(), vv.end(), comp);
    for(auto it : vv) {
        int root1 = FindParent(it->A);int root2 = FindParent(it->B);
        if((root1 == root2 && root1 == -1) || root1 != root2) {
            cost += it->length*100;
            parent[root1] = root2;
        }
    }
    int num = 0;
    for(int i = 0; i < N; i++)
        if(parent[i] == -1) {
            num++;
        }
    if(num > 1) {
        printf("No!");
        return 0;
    }
    printf("%.1f", cost);
    return 0;
}
