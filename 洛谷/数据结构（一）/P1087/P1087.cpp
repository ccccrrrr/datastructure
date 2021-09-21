#include <cstdio>
#include <iostream>
#include <string.h>
char s[200000];
int N;
void print(int left, int right) {
    if(left == right) {
        switch (s[left]) {
        case '0': printf("B");break;
        case '1': printf("I");break;
        }
    } else {
        int middle = (left+right)/2;
        print(left, middle);
        print(middle+1, right);
        bool has1 = false, has0 = false;
        for(int i = left; i <= right; i++) {
            if(has1 && has0) {
                break;
            }
            if(s[i] == '0') {
                has0=true;
                continue;
            }
            if(s[i] == '1') {
                has1=true;
                // printf("has1: i:%d", i);
                continue;
            }
        }
                    // printf("left:%d, right:%d\n", left, right);

        if(has1 && has0) {
            printf("F");
        }else if(has0) {
            printf("B");
        } else if(has1) {
            printf("I");
        }
    }
}
int main() {
    scanf("%d", &N);
    scanf("%s", s);
    print(0, strlen(s)-1);
    return 0;
}