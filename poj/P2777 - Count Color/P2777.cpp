#include <bits/stdc++.h>

using namespace std; 

int L, T, O;
int tag[(10000<<2)+5];
int content[(10000<<2)+5];
/*
 * 每一个节点储存该节点代表的区间中所有存在的颜色。所有颜色可以用一个int值表示，如果第一个颜色存在，int中的第1位就为1，反之为0。
 * 求一个区间的所有颜色个数就是求每个子区间的并，求int值有几个1就是最后的结果。
 */
// build:初始化，题目中给出的要求是每一块在最开始都是颜色1，所以只需要初始化成1就可以
void build(int left, int right, int t) {
    for(int i = 1; i <= right; i++) {
        tag[i] = 1;
        content[i] = 1;
    }
}

int colors(int color) {
    int cnt = 0;
    for(int i = 1; i <= 30; i++) {
        if((color & 0x1) == 1) cnt++;
        color >>= 1;
    }
    return cnt;
}

int calc(int left, int right, int t, int l, int r) {
    if(left == l && right == r) {
        return content[t];
    }
    if(tag[t]) {
        tag[t<<1] = tag[t]; tag[t<<1|1] = tag[t];
        content[t<<1]=tag[t]; content[t<<1|1]=tag[t];
        tag[t]=0;
    }
    int middle = (left + right) >> 1;
    if(middle < l) {
        return calc(middle+1, right, t<<1|1, l, r);
    } else if(middle >= r) {
        return calc(left, middle, t<<1, l, r);
    } else if(l <= middle && middle < r) {
        return calc(middle+1, right, t<<1|1, middle+1, r) | calc(left, middle, t<<1, l, middle);
    } else {
        return 0;
    }
}

void update(int left, int right, int t, int l, int r, int color) {
    if(left == l && right == r) {
        tag[t] = 1 << (color - 1);
        content[t] = 1<<(color-1);
        return;
    }
    // push down operation
    if(tag[t]) {
        tag[t<<1] = tag[t];tag[t<<1|1] = tag[t];
        content[t<<1]=tag[t];content[t<<1|1]=tag[t];
        tag[t] = 0;
    }

    // 递归更新两棵子树的颜色
    int middle = (left + right) >> 1;
    if(l > middle) update(middle+1, right, t<<1|1, l, r, color);
    else if(r <= middle) update(left, middle, t<<1, l, r, color);
    else if(l <= middle && middle < r){
        update(middle+1, right, t<<1|1, middle+1, r, color);
        update(left, middle, t<<1, l, middle, color);
    } else {
        return;
    }
    // 更新完毕后，更新根的颜色种类
    content[t] = content[t<<1] | content[t<<1|1];
}

int main() {
    scanf("%d%d%d", &L, &T, &O);
    int a, b, d;
    char c;
    build(1, L, 1);
    while(O--) {
        getchar();
        c = getchar();
        switch (c) {
        case 'P':
            scanf("%d %d", &a, &b);
            printf("%d\n", colors(calc(1, L, 1, a, b)));
            break;
        case 'C':
            scanf("%d %d %d", &a, &b, &d);
            update(1, L, 1, a, b, d);
            break;
        }
    }
    return 0;
}