// #include <cstdio>
// using namespace std;

int f(int a[], unsigned len) {
    int i, sum = 0;
    for(i = 0; i <= len-1; i++) {
        sum += a[i];
    }
    return sum;
}

// int main() {
//     int a[5] = {1, 2, 3, 4, 6};
//     printf("%d\n", f(a, 5));
//     // printf("%d\n", f(a, 0));
//     return 0;
// }