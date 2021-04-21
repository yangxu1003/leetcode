class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;//起始窗口
        int sum = 0;//滑动窗口数值之和
        int result = 0;
        for(int right = 0; right < nums.size(); ++right)
        {
            sum += nums[right];

            while(sum >= target)
            {
                int length = right-left+1;//子序列长度

                if(result == 0)
                {
                    result = length;
                }
                else
                {
                    result = result > length ? length : result;
                }
                sum -= nums[left++];//不断变更起始位置

            }
        }

        return result;
    }
};