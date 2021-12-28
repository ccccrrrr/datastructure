#include <bits/stdc++.h>

using namespace std;

#define MAX 40000
int cnt = 0;
int N;
struct Node {
    int left, right, height;
} n[MAX+1];

bool cmp(struct Node a, struct Node b) {
    return a.height < b.height;
}
int tree[(MAX *10) + 1];
int tag[(MAX * 10) + 1];
int p[(MAX<<2) + 1];

int search(int val) {
    // 二分法查找对应点
    int l = 1;
    int r = cnt;
    int middle = (l + r) / 2;
    while(l <= r) {
        if(p[middle] == val) return middle;
        if(p[middle] < val) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
        middle = (l + r) / 2;
    }
    return 0;
}

void build(int left, int right, int t) {
    // 线段树节点t代表[p[left], p[right])区间的值，由于是左开右闭的区间，因此不会出现left==right的情形
    if(left + 1 == right) {
        tree[t] = 0;
        return;
    }
    // 不可能会出现middle == right 或者 middle == left的情况
    int middle = left + ((right- left) >> 1);
    build(left, middle, t << 1);
    build(middle, right, (t << 1)|1);
}

void Insert(int left, int right, int height, int tree_left, int tree_right, int t) {
    // printf("left: %d, right: %d, height: %d, tree_left: %d, tree_right: %d, t: %d\n", left, right, height, tree_left, tree_right, t);
    // left right height表示的是要插入的原始线段的区间和高度
    // tree_left, tree_right t 表示当前位于线段树节点t，且其范围为[tree_left, tree_right)
    if(left == tree_left && right == tree_right) {
        tree[t] = height; // 由于插入线段是根据高度由大到小排序过的，所以越后面的树肯定是越高的
        // 我在这里并不知道tag是做什么用的...
        return;
    }

    int middle = (tree_left + tree_right) / 2;
    if(left >= middle) {
        // 说明要插入的线段的范围是该节点的左子树区间的子集
        Insert(left, right, height, middle, tree_right, (t<<1)+1);
        return;
    }
    if(middle >= right) {
        Insert(left, right, height, tree_left, middle, (t<<1));
        return;
    }
    Insert(left, middle, height, tree_left, middle, t << 1);
    Insert(middle, right, height,  middle, tree_right, (t<<1)+1);
}

long long int Solve(int left, int right, int t, int h) {
    // 线段树的节点t代表[left, right)的面积
    // printf("left: %d, right: %d, t: %d\n", left, right, t);
    if(h > tree[t]) {
        tree[t] = h;
    }
    if(left + 1 == right) return (long long int)(p[right]-p[left]) * (long long int)tree[t];
    return Solve(left, left+((right-left)>>1), t<<1, tree[t]) + Solve(left+((right-left)>>1), right, (t<<1)+1, tree[t]);
}

int main() {
    // freopen("P2061_2.in", "r", stdin);
    scanf("%d", &N);    
    for(int i = 1; i <= N; i++) {
        scanf("%d %d %d", &n[i].left, &n[i].right, &n[i].height);
        // 离散化
        p[++cnt] = n[i].left;
        p[++cnt] = n[i].right;
    }
    fclose(stdin);

    sort(p+1, p+cnt+1);
    sort(n+1, n+N+1, cmp);
    // // [p[1], p[2])是一个叶子节点代表的区间
    build(1, cnt, 1);

    for(int i = 1; i <= N; i++) {
        int l = search(n[i].left);
        int r = search(n[i].right);
        Insert(l, r, n[i].height, 1, cnt, 1);
    }

    printf("%lld", Solve(1, cnt, 1, 0));
    return 0;
}