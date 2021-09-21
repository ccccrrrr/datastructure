#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int level;

int r;
void print(int current, int total) {
    




}


vector<pair<int,int>> ignore;
int main() {

    scanf("%d", &level);
    scanf("%d", &r);
    for(int i = 0; i < r; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        ignore.push_back(make_pair(x, y));
    }



    return 0;
}