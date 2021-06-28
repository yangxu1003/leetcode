string mapString[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
class Solution {
public:
    void dfs(string& digits, vector<string>& ret, string cur, int idx)
    {
        if(idx == digits.size())
        {
            ret.push_back(cur);
            return;
        }

        //找到当前字符在string映射表中的位置
        int curIdx = digits[idx] - '0';
        string str = mapString[curIdx];

        for(char& ch : str)
        {
            dfs(digits, ret, cur + ch, idx + 1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits.empty())
        {
            return ret;
        }

        dfs(digits, ret, "", 0);
        
        return ret;
    }
};