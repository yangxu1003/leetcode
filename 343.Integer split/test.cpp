class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; ++i)
        {
            for(int j = 1; j <= i/2; ++j)
            {
                //j*(i-j)代表把i拆分为j和i-j两个数相乘，
                //j*dp[i-j]代表把i拆分为j和把i-j这个数继续拆分求i-j的乘积最大值dp[i-j]
                dp[i] = max(dp[i],max((i - j) * j, j * dp[i - j]));
            }
        }

        return dp[n];
    }
};