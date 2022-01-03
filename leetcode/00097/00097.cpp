// 0ms - 100%
// 6.1MB - 92.96%


class Solution {
public:

    // bool dfs(string& s1, string& s2, string& s3, int ptr1, int ptr2, int ptr3, int s3_size) {
    //     if(ptr3 == s3_size) return true;
    //     if(ptr1 < s1.size() && s1[ptr1] == s3[ptr3]) 
    //         if(dfs(s1, s2, s3, ptr1+1, ptr2, ptr3+1, s3_size)) 
    //             return true;
    //     if(ptr2 < s2.size() && s2[ptr2] == s3[ptr3])
    //         if(dfs(s1, s2, s3, ptr1, ptr2+1, ptr3+1, s3_size))
    //             return true;
    //     return false;
    // }

    bool isInterleave(string s1, string s2, string s3) {
        // 很明显的双指针？
        // 并不...实际上并不一定是双指针
        // dfs巨慢...
        // 看了题解发现可以用动态规划做...
        char dp[101][101] = {{0}};
        int ss1 = s1.size(); int ss2 = s2.size();
        int ss3 = s3.size();
        if(ss1 + ss2 != ss3) return false;
        dp[0][0] = 1;
        for(int i = 1; i <= ss1; i++)
            if(s1[i-1] == s3[i-1]) dp[i][0] = 1;
            else break;
        for(int i = 1; i <= ss2; i++)
            if(s2[i-1] == s3[i-1]) dp[0][i] = 1;
            else break;
        for(int i = 1; i <= ss1; i++) {
            for(int j = 1; j <= ss2; j++) {
                if(dp[i-1][j] == 1 && s1[i-1] == s3[i-1+j-1+1]) dp[i][j] = 1;
                if(dp[i][j-1] == 1 && s2[j-1] == s3[i-1+j-1+1]) dp[i][j] = 1;
            }
        }
        return dp[ss1][ss2] == 1;

    }
};