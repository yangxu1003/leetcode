class Solution {
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& ret, vector<int>& subRet, int target, int idx, int sum)
    {
    
        if(sum >= target)
        {
            if(sum == target)
            {
                ret.push_back(subRet);
            }  
            return;
        }

        for(int i = idx; i < candidates.size(); ++i)
        {
            if(candidates[i] > target)
            {
                continue;
            }
            subRet.push_back(candidates[i]);//存入
            dfs(candidates, ret, subRet, target, i, sum+candidates[i]);//递归继续从i开始
            subRet.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        vector<int> subRet;
        dfs(candidates, ret, subRet, target, 0, 0);

        return ret;
    }
};