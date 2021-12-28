#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 60000
// 可以用树状数组维护当前牛之前的牛的个数，和当前牛之前的牛的坐标和。当然首先需要根据听力值排序，这样就保证了能量和最小。
// 那么问题来了，当加入下一头牛时，应该怎么更新树状数组呢？
// 1. 根据耳聋程度由小到大排序，每次增加耳聋程度最小地牛，这样每次增加的音量肯定的是最小的，后续不会有减少音量的情况。
// 2. 使用树状数组进行区间的维护，维护的是当前的坐标值，由于我无法知道新加入Moo的坐标是比之前的大还是小，因此无法直接使用加法直接计算所有的坐标之和。所以需要使用两个树状数组，一个是所有坐标之和，一个是比当前坐标小的树状数组。
// 由于N, V, x它们的值最大都为50000，因此区间用树状数组来维护是可行的
struct Moo {
    long long int x, w;
    Moo(){}
    Moo(long long int x, long long int w) : x(x), w(w){}
    bool operator <(Moo a) {
        return w < a.w;
    }
};
Moo m[MAX_SIZE];
long long int N;
long long int max_size;
long long int num[MAX_SIZE+1];
long long int sum[MAX_SIZE+1];
long long int present_num = 0;
long long int present_x_sum = 0;
long long int lowbit(int p) {return p&(-p);}

void Add(long long int array[], int p, int val) {
    while(p <= max_size) {
        array[p] += val;
        p += lowbit(p);
    }
}

long long int GetSum(long long int array[], int p) {
    long long int sum = 0;
    while(p > 0) {
        sum += array[p];
        p -= lowbit(p);
    }
    return sum;
}

int main() {
    scanf("%lld", &N);
    int w, x;
    for(long long int i = 0; i < N; i++) {
        scanf("%lld %lld", &m[i].w, &m[i].x);
        max_size = max(max_size, m[i].x);
    }
    sort(m, m+N);
    long long int val1 = 0, val2 = 0, val3 = 0;
    long long int res = 0;
    for(long long int i = 0; i < N; i++) {
        // val1 代表在m[i].x之前的所有已经被记录的moo的坐标之和
        val1 = GetSum(sum, m[i].x);
        // val2 代表在m[i].x之前的所有被记录的moo的数量
        val2 = GetSum(num, m[i].x);
        // printf("present_sum: %lld, present_num: %lld, val1: %lld, val2: %lld,  x: %lld, w: %lld\n", present_x_sum, present_num, val1, val2, m[i].x, m[i].w);
        res += (m[i].x * val2 - val1) * m[i].w + (present_x_sum - val1 - (present_num - val2) * m[i].x) * m[i].w;
        // printf("res: %lld\n", res);
        Add(num, m[i].x, 1);
        Add(sum, m[i].x, m[i].x);
        present_x_sum += m[i].x;
        present_num += 1;
    }
    printf("%lld", res);
    return 0;
}
