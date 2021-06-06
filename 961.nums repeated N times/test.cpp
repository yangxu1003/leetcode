class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for(size_t i = 0; i < nums.size(); ++i)
        {
            countMap[nums[i]]++;
            if(countMap[nums[i]] == nums.size() / 2)
            {
                return nums[i];
            }
        }

        return -1;
    }
};