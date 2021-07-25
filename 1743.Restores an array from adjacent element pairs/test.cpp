class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> map;
        vector<int> ret;
        //将k，v结构存入map
        for(auto& e : adjacentPairs)
        {
            map[e[0]].push_back(e[1]);
            map[e[1]].push_back(e[0]);
        }

        //找到v只有一个的pair
        for(auto& e : map)
        {
            if(e.second.size() == 1)
            {
                ret.push_back(e.first);
                ret.push_back(e.second[0]);
                break;
            }
        }

        while(map[ret.back()].size() == 2)
        {
            if(ret[ret.size()-2] == map[ret.back()][0])//表示构成死环了
            {
                ret.push_back(map[ret.back()][1]);
            }
            else
            {
                ret.push_back(map[ret.back()][0]);
            }
        }

        return ret;
    }
};