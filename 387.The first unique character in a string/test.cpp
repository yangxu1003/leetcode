class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(auto ch : s)
        {
            count[ch-'a'] += 1;
        }
        
        for(int j = 0; j < s.size(); ++j)
        {
            if(count[s[j]-'a'] == 1)
            {
                return j;
            }
        }
        return -1;
    }
};