class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int len = num.size();
        for(int i = 0; i < len; ++i)
        {
            while(k && !ans.empty() && ans.back() > num[i])
            {
                ans.pop_back();
                --k;
            }
            ans.push_back(num[i]);
        }

        while(k--)
        {
            ans.pop_back();//保证现在有的元素数量为len-k
        }
        
        int i = 0;

        while(i < ans.size() && ans[i] == '0')//防止首位为'0'
        {
            ++i;
        } 

        return i == ans.size() ? "0" : ans.substr(i);
    }
};