class Solution {
public:
    int massage(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 0;
        }
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];

        for(int i = 2; i < dp.size(); ++i)
        {
            dp[i] = max(nums[i-1] + dp[i-2], dp[i-1]);
        }

        return dp[n];
    }
};