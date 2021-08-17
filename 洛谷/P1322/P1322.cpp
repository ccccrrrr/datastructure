#include <cstdio>
#include <algorithm>

using namespace std;

long long int handle() {
    char c;
    long int res = 0;
    while((c=getchar()) != EOF && c != ']' && c != '\n') {
        while(c == ' ' || c == '[') c = getchar();
        switch(c) {
            case 'R':
                for(int i = 0; i < 6; i++) 
                    getchar();
                int repeat;
                scanf("%d", &repeat);
                res += repeat * handle();
                break;
            case 'B':
                for(int i = 0; i < 2; i++) 
                    getchar();
                int back;
                scanf("%d", &back);
                res -= back;
                break;
            case 'F':
                getchar();
                getchar();
                int foward;
                scanf("%d", &foward);
                res += foward;
                break;
            case ']':
            case 0:
            case '\n':
                return res;
        }
    }
    return res;
}

int main() {
    printf("%lld", abs(handle()));
    return 0;
}