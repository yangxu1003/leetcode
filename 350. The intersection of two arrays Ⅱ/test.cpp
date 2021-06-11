class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //先将一个数组存入哈希map，然后遍历nums2从map中找交集
        unordered_map<int, int> hashmap;

        for(auto& e : nums1)
        {
            hashmap[e]++;
        }

        vector<int> ret;
        
        for(auto& e : nums2)
        {
            if(hashmap[e] > 0)
            {
                ret.push_back(e);
                hashmap[e]--;
            }
        } 

        return ret;
    }
};