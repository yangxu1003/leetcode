class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i] == nums[i-1])//去重i
            {
                continue;
            }

            for(int j = i + 1; j < nums.size(); ++j)
            {

                if(j > i + 1 && nums[j] == nums[j-1])//去重j
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while(left < right)
                {
                    if(nums[i] + nums[j] + nums[left] + nums[right] < target)
                    {
                        ++left;
                    }
                    else if(nums[i] + nums[j] + nums[left] + nums[right] > target)
                    {
                        --right;
                    }
                    else
                    {
                        ret.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});

                        while(left < right && nums[left] == nums[left+1])//去重
                        {
                            ++left;
                        }
                        while(left < right && nums[right] == nums[right-1])
                        {
                            --right;
                        }

                        ++left;
                        --right;
                    }
                }
            }
        }

        return ret;
    }
};