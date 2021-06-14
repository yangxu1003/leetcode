class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //1.将所有的数据加入哈希表中的同时进行去重
        //2.查找一个连续数组，我们可以从该段数组的最小值 x 开始查询
        //3.如果x-1不在set之中，说明这个数没有前驱，即这个数是"当前连续数组的最小值"，然后用这个数，依次增大在哈希表中进行查找
        unordered_set<int> set;
        for(auto& e : nums)
        {
            set.insert(e);
        }

        int maxLenth = 0;
        int length = 0;

        for(size_t i = 0; i < nums.size(); ++i)//找连续序列
        {
            if(set.find(nums[i]-1) != set.end())
            {
                continue;//找到连续序列的最小值
            }

            int num = nums[i]+1;
            length = 1;//恢复为1

            while(set.find(num) != set.end())//找num+1
            {
                length++;
                num++;
            }

            maxLenth = max(length, maxLenth);
        }

        return maxLenth;
    }
};