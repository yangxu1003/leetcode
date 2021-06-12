class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        //将s1和s2拼接成一个字符串，存入map
        if(s1.empty())
        {
            s1 = s2;
        }
        else
        {
            s1 += ' ';
            s1 += s2;
        }
        
        unordered_map<string, int> map;
        
        for(size_t i = 0; i < s1.size(); ++i)
        {
            string tmp;
            tmp.clear();
            while(i < s1.size() && s1[i] != ' ')//走到空格停止
            {
                tmp += s1[i];
                i++;
            }

            map[tmp]++;//将单词存入map
        }

        vector<string> ret;
        for(auto& e : map)
        {
            if(e.second == 1)
            {
                ret.push_back(e.first);
            }
        }

        return ret;
    }
};