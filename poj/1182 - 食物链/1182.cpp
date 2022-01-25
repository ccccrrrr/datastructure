#include <cstdio>
using namespace std;
#define MAX_ANIMAL 50000

class Node {
    public:
        int parent;
        char relation;
    Node(int parent, int relation):parent(parent), relation(relation){}
};

int N, K;
Node* animal[MAX_ANIMAL+1];

int findParent(int child) {
    int parent = child;
    int relation = 0;
    while(animal[parent]->parent != parent) {
        relation += animal[parent]->relation;
        parent = animal[parent]->parent;
    }
    animal[child]->parent = parent;
    animal[child]->relation = relation % 3;
    return parent;
}

int main() {
    scanf("%d %d", &N, &K);
    int a, b, c;
    int lie = 0;
    for(int i = 1; i <= N; i++) {
        animal[i] = new Node(i, 0);
    }
    for(int i = 0; i < K; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if(b > N || c > N) {
            lie++;continue;
        }
        if(a == 2 && b == c) {
            lie++;continue;
        }
        int rootx = findParent(b);
        int rooty = findParent(c);
        if(a == 1) {
            // printf("b:%d, c:%d\n", b, c);
            // 如果b和c在一个并查集中，就可以判断是否有矛盾
            if(rootx == rooty && animal[b]->relation != animal[c]->relation) {
                lie++;continue;
            }
            if(rootx != rooty) {
                // 合并
                animal[rootx]->parent = rooty;
                // animal[a]->parent = b
                // animal[a]->relation = a -> relation
                // rootx -> rooty => rootx -> b -> c -> rooty
                animal[rootx]->relation = (animal[c]->relation - animal[b]->relation + 3) % 3;
            }
        } else {
            // a eat b
            // animal[a]->parent = b
            // animal[a]->relation = 1
                if(rootx == rooty && (animal[b]->relation-animal[c]->relation+3)%3 != 1) {
                    lie++;continue;
                }
                if(rootx != rooty) {
                    animal[rootx]->parent = rooty;
                    animal[rootx]->relation = (1+animal[c]->relation - animal[b]->relation + 3) % 3;
                }
        }
    }
    printf("%d", lie);
}