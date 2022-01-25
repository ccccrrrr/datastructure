#include <bits/stdc++.h>
using namespace std;

int _solution(string &S) {
    // write your code in C++14 (g++ 6.2.0)
    if(S.size() == 0) return 0;
    int fragment_num = 0;
    int _max = 0;
    char tmp_char = 0;
    int tmp_length=0;
    int ss = S.size();
    for(int i = 0; i < ss; ++i) {
        if(S[i] != tmp_char) {
            fragment_num++;
            tmp_char = S[i];
            _max = max(_max, tmp_length);
            tmp_length = 1;
        } else {
            tmp_length++;
        }
    }
    // if(ss >= 2 && S[ss-1] != S[ss-2]) fragment_num++;
    _max = max(_max, tmp_length);
    // printf("fragmentnum: %d, ss: %d, _max: %d\n", fragment_num, ss, _max);
    long long int res = (long long int)_max * (long long int)fragment_num - (long long int)ss;
    return (int) res;
}

int main() {
    string s = "a";
    printf("%d\n", _solution(s));
    return 0;
}