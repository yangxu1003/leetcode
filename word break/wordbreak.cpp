class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(s.empty())
        {
            return false;
        }
        
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        
        for(int i = 1; i <=  s.size(); ++i)
        {
            for(int j = i-1; j >= 0; --j)
            {
                // F(i): true{j < i && F(j) && substr[j+1,i]能在词典中找到} OR false
                // 第j+1个字符的索引为j
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end())
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[s.size()];
    }
};