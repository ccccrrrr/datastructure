#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

const int M = 5e5+5;
// #define M 50000
long long int N;
long long int res;
int mylist[M];
int minstack[M];
long long int minptr;
int main() {
    res = 0;
    stack<int> mystack;
    minptr = -1;
    scanf("%lld", &N);
    for(long long int i = 0; i < N; i++) {
        scanf("%d", &mylist[i]);
        while(!mystack.empty() && mylist[mystack.top()] < mylist[i]) mystack.pop();
        while(minptr >= 0 && mylist[minstack[minptr]] >= mylist[i]) minptr--;
        // printf("i: %lld, mylist[i]: %d, minptr: %lld\n", i, mylist[i], minptr);
        // if(minptr == -1) {
        //     mystack.push(i);
        //     minstack[++minptr] = i;
        //     continue;
        // }
        int xx=0;
        if(!mystack.empty()) {
            /* upper_bound method search for [begin, end) element which is greater or equal than num*/
            xx = upper_bound(minstack, minstack+minptr+1, mystack.top()) - minstack;
        } else {
            xx = upper_bound(minstack, minstack+minptr+1, -1) - minstack;
            // printf("%d\n", xx);
        }
        if(xx == minptr+1) {
            /* result not found */
            mystack.push(i);
            minstack[++minptr] = i;
            continue;
        }
        long long int tempRes = i - minstack[xx] + 1;
        if(tempRes > res) {
            // printf("tempRes: %lld, i: %lld, xx: %d, minptr: %lld\n", tempRes, i, minstack[xx], minptr);
            res = tempRes;
        }
        mystack.push(i);
        minstack[++minptr] = i;
    }
    printf("%lld", res);
    return 0;
}