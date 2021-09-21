#include <cstdio>
#include <algorithm>
#include <deque>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

int t;
int s;
std::string str;

int main() {
    while(scanf("%d", &t) != 0) {
        printf("Scenario #%d\n", ++s);
        queue<int> onelist[t];
        deque<int> res;
        int isPushed[t];
        queue<int> iteratorList[t];
        for(int i = 0; i < t; i++) {
            int num;
            scanf("%d", &num);
            for(int j = 0; j < num; j++) {
                int x;
                scanf("%d", &x);
                onelist[i].push(x);
            }
        }
            for(;;) {
                cin>>str;
                if(str == "STOP") {
                    break;
                } else if(str == "ENQUEUE") {
                    int xx;
                    scanf("%d", &xx);
                    int ii=0;
                    for(; ii < t; ii++) {
                        if(!onelist[ii].empty() && onelist[ii].front() == xx) {
                            break;
                        }
                    }
                    if(iteratorList[ii].empty()) {
                        res.push_back(xx);
                        iteratorList[ii].push(xx);
                        onelist[ii].pop();
                    } else {
                        auto iter = res.begin();
                        for(;iter != res.end(); iter++) {
                            if((*iter) == iteratorList[ii].back()) {
                                break;
                            }
                        }
                        if(iter == res.end() || iter == res.end()-1) {
                            res.push_back(xx);
                        } else {
                            res.insert(++iter, xx);
                        }
                        iteratorList[ii].push(xx);
                        onelist[ii].pop();
                    }
                } else if(str == "DEQUEUE") {
                    printf("%d\n", res.front());
                    for(int iii = 0; iii < t; iii++) {
                        if(!iteratorList[iii].empty() && iteratorList[iii].front() == res.front()) {
                            iteratorList[iii].pop();
                            break;
                        }
                    }
                    res.pop_front();
                }
            }
            printf("\n");
    }
    return 0;
}