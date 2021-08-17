#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
long long int N = 2e5+1;
// stack<long long int> mystack;
stack<long long int> maxstack;
int choice;
int main() {
    scanf("%lld", &N);
    for(long long int i = 0; i < N; i++) {
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                long long int X;
                scanf("%lld", &X);
                // mystack.push(X);
                if(maxstack.empty()) {
                    maxstack.push(X);
                } else {
                    long long int tempMax = X > maxstack.top() ? X : maxstack.top();
                    // printf("tempMax: %lld\n", tempMax);
                    maxstack.push(tempMax);
                }
                break;
            case 1:
                if(!maxstack.empty()) {
                    // mystack.pop();
                    maxstack.pop();
                }
                break;
            case 2:
                if(maxstack.empty()) {
                    printf("0\n");
                } else {
                    printf("%lld\n", maxstack.top());
                }
        }
    }
    return 0;
}