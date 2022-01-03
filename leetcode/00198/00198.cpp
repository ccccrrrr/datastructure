// 0ms - 100.00%
// 7.4MB - 83.31%


class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[101][2] = {{0}};
        // dp[i][0] 代表第i间房子没有被偷的最大收入
        // dp[i][1] 代表第i间房子被偷了，[1,i]的最大收入
        dp[0][0] = 0, dp[0][1] = 0;
        int s = nums.size();
        for(int i = 0; i < s; i++) {
            dp[i+1][0] = max(dp[i][0], dp[i][1]);
            dp[i+1][1] = dp[i][0]+nums.at(i);
        }
        return max(dp[s][1], dp[s][0]);
    }
};