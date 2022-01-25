# 00070

简单动态规划

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; ++i) {
            if(i == n-1) {
                dp[i+1] += dp[i];
            } else {
                dp[i+1] += dp[i];
                dp[i+2] += dp[i];
            }
        }
        return dp[n];
    }
};
```

但内存消耗只超过了8.78%，还是可以继续优化的。

实际上，这个动态规划方程写的并不是最简单的

原来的动态规划方程为：
$$
dp[i]=dp[i]+dp[i-1]\\
dp[i]=dp[i]+dp[i-2]
$$
其实转换一下思路，就是
$$
dp[i]=dp[i-1]+dp[i-2]
$$
这样会比原来的思路更直接一些。

当然通过这个式子，我们也可以知道整一个程序只需要三个变量就可以实现这个算法。空间复杂度可以从$O(n)$压缩到$O(1)$。

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(3, 0);
        int pointer = 0;
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        if(n == 1) return dp[1];
        if(n == 2) return dp[2];
        for(int i = 2; i < n; ++i, pointer = (pointer+1)%3) {
            dp[pointer] = dp[(pointer+1)%3]+dp[(pointer+2)%3];
        }
        return dp[(pointer+2)%3];
    }
};
```

这样空间复杂度就可以击败94.76%的人啦！