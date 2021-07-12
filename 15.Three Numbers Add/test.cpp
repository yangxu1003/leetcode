class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i)
        {
            //排序后第一个元素大于0，直接返回
            if(nums[i] > 0)
            {
                return ret;
            }

            //去重
            if(i > 0 && nums[i] == nums[i-1])
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right)
            {
                if(nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else if(nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else
                {
                    ret.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    //去重
                    while(left < right && nums[left] == nums[left + 1])
                    {
                        left++;
                    }

                    while(left < right && nums[right] == nums[right -1])
                    {
                        right--;
                    }
                    ++left;
                    --right;
                }
            } 
        }

        return ret;
    }
};