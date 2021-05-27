class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        //1.用map统计单词出现的频率，map将单词按照ASCII进行了排序
        map<string, int> countMap;
        for(auto& e : words)
        {
            countMap[e]++;
        }

        //2.用multimap对单词出现的频率，排降序
        multimap<int, string, greater<int>> sortMap;//排降序
        for(auto& e : countMap)
        {
            sortMap.insert(make_pair(e.second, e.first));
        }

        vector<string> v;
        auto it = sortMap.begin();
        while(k--)
        {
            v.push_back(it->second);
            it++;
        }

        return v;
    }
};