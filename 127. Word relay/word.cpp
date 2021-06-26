class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());//哈希查找

        unordered_set<string> book;//标记以访问过的
        book.insert(beginWord);

        queue<string> q;
        q.push(beginWord);
        int step = 1;

        while(!q.empty())
        {
            int n = q.size();

            while(n--)
            {
                string cur = q.front();//取出当前元素
                q.pop();

                if(cur == endWord)//找到了
                {
                    return step;
                }

                for(int i = 0; i < cur.size(); ++i)//尝试转换当前每一个单词的位置
                {
                    string tmp = cur;
                    for(char ch = 'a'; ch <= 'z'; ++ch)//替换当前字母
                    {
                        tmp[i] = ch;

                        if(dict.find(tmp) != dict.end() && book.find(tmp) == book.end())//字典有并且没访问过
                        {
                            q.push(tmp);
                            book.insert(tmp);
                        }
                    }
                }
            }
            ++step;

        }

        return 0;
    }
};