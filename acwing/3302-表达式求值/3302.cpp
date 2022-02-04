#include <bits/stdc++.h>
using namespace std;
stack<char> op;
stack<int> nums;
string s;
int t=-1;

void eval() {
    int x = nums.top();nums.pop();
    int y = nums.top();nums.pop();
    switch(op.top()) {
        case '+':
        // printf("%d+%d\n", y,x);
            op.pop();
            if(!op.empty() && op.top() == '-')
                nums.push(y-x);
            else
                nums.push(y+x);
            break;
        case '-':
        // printf("%d-%d\n",y,x);
        op.pop();
            if(!op.empty() && op.top() == '-')
                nums.push(y+x);
            else
                nums.push(y-x);
            break;
        case '*':
        // printf("%d*%d\n",y,x);
        op.pop();
        if(!op.empty() && op.top() == '/') {
            nums.push(y/x);
        } else {
            nums.push(y*x);
        }
        break;
        case '/':
        op.pop();
        if(!op.empty() && op.top() == '/') {
            nums.push(y*x);
        } else {
            nums.push(y/x);
        }
        break;
    }
    // op.pop();
}

int main() {
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i) {
        if(s[i] == '(') {
            op.push(s[i]);
        } else if(s[i] == ')') {
            while(op.top() != '(') {
                eval();
            }
            op.pop();
        } else if(s[i] == '-' || s[i] == '+') {
            while(!op.empty() && (op.top() == '*' || op.top() == '/')) {
                eval();
            }
            op.push(s[i]);
        } else if(s[i] == '*' || s[i] == '/') {
            // 不知道为什么，如果不加这个while循环出来的结果就是错的
            while(!op.empty() && (op.top() == '*' || op.top() == '/')) {
                eval();
            }
            op.push(s[i]);
        } else if(s[i] >= '0' && s[i] <= '9') {
            t = 0;
            int p = i;
            while(p < s.size() && s[p] >= '0' && s[p] <= '9') {
                t = 10 * t + s[p]-'0';
                p++;
            }
            nums.push(t);
            i = p-1;
        } else {
            // 可能是空格
        }
    }
    while(!op.empty()) {
        eval();
    }
    printf("%d", nums.top());
    return 0;
}