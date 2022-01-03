// 运算时间超过100%


class Solution {
public:
    int numDecodings(string s) {
        int dp[100] = {0};
        memset(dp, 0, sizeof(dp));
        int ss = s.size();
        for(int i = 0; i < ss; i++) {
            if(i == 0) {
                if(s[0] == '0')
                    return 0;
                dp[0] = 1;
            } else if(i == 1){
                if(s[i-1] == '1' || (s[i-1] == '2' && (s[i] <= '6' && s[i] >= '0')))
                    dp[i] += 1;
                if(s[i] >= '1' && s[i] <= '9')
                    dp[i] += dp[i-1];                
            } else {
                if(s[i-1] == '1' || (s[i-1] == '2' && (s[i] <= '6' && s[i] >= '0'))) {
                    dp[i] += dp[i-2];
                }
                if(s[i] >= '1' && s[i] <= '9')
                    dp[i] += dp[i-1];
            }
        }
        return dp[ss-1];
    }
};