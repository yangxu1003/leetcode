class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for(int i = 0; i < 32; ++i)//int类型为32位，因此只需统计32位
        {
            int count = 0;
            for(auto e : nums)//统计所有数字的当前位
            {
                count += (e >> i) & 1;//统计当前位1的个数
            }
            ret += (count % 3) << i; //计算目标数的当前位的值
        }

        return ret;
    }
};
