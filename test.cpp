#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // 注意，string并没有reverse方法
    string single_multiply(string num1, char c) {
        string res = "";
        int adds = 0;
        int l = num1.size()-1;
        for(; l >= 0; l--) {
            res.push_back((c * (num1.at(l)-'0') + adds) % 10 + '0');
            adds = (c * (num1.at(l)-'0') + adds) / 10;
        }
        if(adds != 0) res.push_back(adds + '0');
        else {
            if(res.size() == 0) {
                res = "0";
            } else {
                l = res.size()-1;
                while(l >= 1 && res.at(l) == '0') {
                    res.pop_back(); l--;
                }
            }
        }
        reverse(res.begin(), res.end());
        cout << "multiply: " << res << endl;
        return res;
    }

    string single_add(string res, string tmp) {
        int adds =0;
        string new_res = "";
        int l1 = res.size()-1;
        int l2 = tmp.size()-1;
        while(l1 >=0 && l2 >= 0) {
            new_res.push_back((adds + (res.at(l1)-'0') + (tmp.at(l2) - '0')) % 10 + '0');
            adds = (adds + (res.at(l1)-'0') + (tmp.at(l2) - '0')) / 10;
            l1--;l2--;
        }
        while(l1 >= 0) {
            new_res.push_back((adds + (res.at(l1)-'0')) % 10 + '0');
            adds = (adds + (res.at(l1)-'0')) / 10;
            l1--;
        }
        while(l2 >= 0) {
            new_res.push_back((adds + (tmp.at(l2)-'0')) % 10 + '0');
            adds = (adds + (tmp.at(l2)-'0')) / 10;
            l2--;
        }
        if(adds != 0) new_res.push_back(adds + '0');
            if(res.size() == 0) {
                res = "0";
            } else {
                int l = new_res.size()-1;
                while(res.at(l) == '0' && l >= 1) {
                    res.pop_back(); l--;
                    printf("!");
                }
            }
        reverse(new_res.begin(), new_res.end());
        cout << new_res << endl;
        return new_res;
    }

    string multiply(string num1, string num2) {
        int l = num2.size();
        string res = "";
        for(int i = l-1; i >= 0; i--) {
            string tmp = single_multiply(num1, num2.at(i)-'0');
            for(int k = 0; k < l-1-i; k++)
                tmp.push_back('0');
            string res_ = single_add(res, tmp);
            res = res_;
        }
        return res;
    }
};

int main() {
    Solution *solution = new Solution();
    cout << solution->multiply("123456789", "987654321");
}

