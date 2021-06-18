class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;//哈希表的key为前缀和

        map[0] = 1;// 关键一步，否则会遗漏全部或者单个k的情况

        int SumN = 0;
        int count = 0;
        for(auto& e : nums)
        {
            SumN += e;

            if(map.find(SumN-k) != map.end())
            {
                count += map[SumN-k];//sumN - k = key(前缀和);
            }

            map[SumN]++;//将前n项和存起来
        }

        return count;
    }
};