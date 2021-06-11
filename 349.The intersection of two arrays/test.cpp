class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map1;
        for(auto& e : nums1)
        {
            map1[e]++;
        }

        map<int, int> map2;
        for(auto& e : nums2)
        {
            map2[e]++;
        }

        vector<int> v;
        //unordered_map<Key, T>::iterator it1 = map1.begin();
        auto it1 = map1.begin(), it2 = map2.begin();
        
        while(it1 != map1.end() && it2 != map2.end())
        {
            if((*it1).first == it2->first)
            {
                v.push_back(it1->first);
                it1++;
                it2++;
            }
            else if(it1->first > it2->first)
            {
                it2++;
            }
            else
            {
                it1++;
            }
        }

        return v;
    }
};