#include <cstdio>
#include <string.h>

using namespace std;

char s1[26];
char s2[26];


int findindex(int val) {
    int l = strlen(s1);
    for(int i = 0; i < l; i++) {
        if(s1[i] == val) {
            return i;
        }
    }
    return -1;
}

/*
    print_low:
    left, right are all index in s2

*/
void print_low(int left2, int right2, int left1, int right1) {

    if(right2 < left2) {
        return;
    }

    if(left2 == right2) {
        printf("%c", s2[left2]);
        return;
    }

    int subroot = s2[left2];

    int i = findindex(subroot);

    print_low(left2+1, left2+i-left1, left1, i-1);

    print_low(left2+1+i-left1, right2, i+1, right1);

    printf("%c", s2[left2]);

}

int main() {
    scanf("%s", s1);
    scanf("%s", s2);
    print_low(0, strlen(s1)-1, 0, strlen(s1)-1);


    return 0;
}