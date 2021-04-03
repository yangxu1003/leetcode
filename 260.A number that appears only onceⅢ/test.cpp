class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e : nums)//先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
        {
            ret ^= e;
        }

        int div = 1;
        while((div & ret) == 0)//在异或结果中找到任意为1的位(根据这一位对所有的数字进行分组)
        {
            div <<= 1;
        }

        //在每个组内进行异或操作，得到两个数字。
        vector<int> retArr(2,0);
        for (auto arr : nums) {
            if (arr & div)
            {
                retArr[0] ^= arr;
            } 
            else
            {
                retArr[1] ^= arr;
            }
        }
        return retArr;

    }
};class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ret = 0;
        for(auto e : nums)//先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
        {
            ret ^= e;
        }

        int div = 1;
        while((div & ret) == 0)//在异或结果中找到任意为1的位(根据这一位对所有的数字进行分组)
        {
            div <<= 1;
        }

        //在每个组内进行异或操作，得到两个数字。
        vector<int> retArr(2,0);
        for (auto arr : nums) {
            if (arr & div)
            {
                retArr[0] ^= arr;
            } 
            else
            {
                retArr[1] ^= arr;
            }
        }
        return retArr;

    }
};