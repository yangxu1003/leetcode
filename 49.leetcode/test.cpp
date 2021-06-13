class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //把"异位词" 放到同一個 vector
        //因為字串排序過的順序一樣
        //所以可以先排序過，當作 key 即可把同一類的"异位词"找出來
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;

        for(size_t i = 0; i < strs.size(); ++i)
        {   
            string key = strs[i];
            sort(key.begin(), key.end());

            map[key].push_back(strs[i]);
        }

        for(auto& e : map)
        {
            res.push_back(e.second);
        }

        return res;
    }
};