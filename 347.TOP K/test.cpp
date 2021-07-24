class Solution {
public:
    class mycompare
    {
    public:
        bool operator()(pair<int, int>& left, pair<int, int>& right)
        {
            if(left.second > right.second)
            {
                return true;
            }
            return false;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;//记录数字和频率
        for(auto& e : nums)
        {
            map[e]++;
        }

        //小堆,堆频率排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycompare> q;
        for(auto& e : map)
        {
            q.push(e);
            if(q.size() > k)
            {
                q.pop();
            }
        }

        vector<int> ret(k);
        for(int i = k-1; i >= 0; i--)
        {
            ret[i] = q.top().first;
            q.pop();
        }

        return ret;

    }
};