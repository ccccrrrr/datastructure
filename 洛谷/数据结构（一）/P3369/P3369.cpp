#include <bits/stdc++.h>

using namespace std;

int n;
int x, y;
struct Node {
    int num;
    struct Node * Left;
    struct Node * Right;
};

struct Node * root = nullptr;

void insert_node() {
    int num;
    scanf("%d", &num);
    if(root == nullptr) {
        root = new Node();
        root->num = num;
        return;
    }
    auto ptr = root;
    while(true) {
        if(num < ptr->num) {
            if(ptr->Left) 
                ptr = ptr->Left;
            else {
                ptr->Left = new Node();
                ptr->Left->num = num;
                return;
            }
        } else {
            if(ptr->Right) 
                ptr = ptr->Right;
            else {
                ptr->Right = new Node();
                ptr->Right->num = num;
                return;
            }
        }
    }
}

void delete_node() {
    int num;
    scanf("%d", &num);
    auto ptr = root;
    if(ptr == nullptr) {
        return;
    }
    while(ptr != nullptr) {
        if(ptr->num < num) {
            ptr = ptr->Right;
        } else if(ptr->num > num) {
            ptr = ptr->Left;
        } else {
            if(ptr->Left != nullptr) {
                ptr->num = ptr->Left->num;
                auto deleted = ptr->Left;
                ptr->Left = ptr->Left->Left;
                delete deleted;
            } else if(ptr->Right != nullptr) {
                ptr->num = ptr->Right->num;
                auto deleted = ptr->Right;
                ptr->Right = ptr->Right->Right;
                delete deleted;
            } else {
                delete ptr;
            }

        }
    }
}

int get_node_sum(struct Node * n) {
    if(n == nullptr) {
        return 0;
    }
    if(n->Left == nullptr && n->Right == nullptr) {
        return 1;
    }
    return 1 + get_node_sum(n->Left) + get_node_sum(n->Right);
}

int get_rank(int ele) {
    auto ptr = root;
    if(ptr->num == ele) {
        return get_node_sum(ptr->Left) + 1;
    }
    int res = 0;
    while(ptr->num > ele) {
        if(ptr->Right != nullptr) {
            if(ptr->Right->num > ele) {
                return get_node_sum(ptr->Left) + 1 + get_node_sum(ptr->Right->Left);
            } else if(ptr->Right->num == ele) {
                return get_node_sum(ptr->Left) + 1;
            } else if(ptr->Right->num < ele) {
                res += get_node_sm()
            }
        }

    }
}

int find_through_rank() {

}

void find_before() {

}

void find_next() {

}

int main() {
    scanf("%d", &n);
    int s;
    for(int i = 0; i < n; i++) {
        scanf("%d", &s);
        switch(s) {
            case 1: insert_node();break;
            case 2: delete_node();break;
            case 3: int t;scanf("%d", &t);printf("%d", get_rank(t));break;
            case 4: printf("%d", find_through_rank());break;
            case 5: find_before();break;
            case 6: find_next();break;
            
        }
    }
    return 0;
}