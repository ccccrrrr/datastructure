
// 0ms - 100.00%
// 6.9MB - 13.43%

class Solution {
public:

    void dfs(string& s, vector<string>& res, int p, string tmp, int num) {
        if(num == 4 && p == s.size()) {
            string t(tmp.begin(), tmp.end()-1);
            res.push_back(t);
        }
        if(num == 4 || p == s.size()) return;
        // 一位
        if(s[p] >= '0' && s[p] <= '9') {
            tmp.push_back(s[p]);tmp.push_back('.');
            dfs(s, res, p+1, tmp, num+1);
            tmp.pop_back();tmp.pop_back();
        }
        // 两位
        if(p+1 < s.size() && (s[p] != '0')) {
            tmp.push_back(s[p]);tmp.push_back(s[p+1]);tmp.push_back('.');
            dfs(s, res, p+2, tmp, num+1);
            tmp.pop_back();tmp.pop_back();tmp.pop_back();
        }
        // 三位
        if(p+2 < s.size()) {
            if(s[p] == '0' || s[p] >= '3') return;
            if(s[p] == '2' && s[p+1] >= '6') return;
            if(s[p] == '2' && s[p+1] == '5' && s[p+2] >= '6') return;
            tmp.push_back(s[p]);tmp.push_back(s[p+1]);tmp.push_back(s[p+2]);tmp.push_back('.');
            dfs(s, res, p+3, tmp, num+1);
            tmp.pop_back();tmp.pop_back();tmp.pop_back();tmp.pop_back();
        }

    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string tmp;
        // start from 0
        dfs(s, res, 0, tmp, 0);
        return res;
    }
};