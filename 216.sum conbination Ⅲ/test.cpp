class Solution {
public:
    void dfs(vector<vector<int>> &ret, vector<int> &path, int sum, int k, int n, int idx)
    {
        if(sum > n)
        {
            return;
        }
        if(path.size() == k)
        {
            if(sum == n)
            {
                ret.push_back(path);
            }
            return;
        }

        for(int i = idx; i <= 9; ++i)
        {
            path.push_back(i);
            dfs(ret, path, sum+i, k, n, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> path;
        dfs(ret, path, 0, k, n, 1);
        return ret;
    }
};