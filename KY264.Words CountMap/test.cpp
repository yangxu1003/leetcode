#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        map<string, int> countMap;
        string tmp;
        
        // 分割单词，采用map统计每个单词出现的次数
        for(size_t i = 0; i < s.size(); ++i)
        {
            if(s[i] == ' ' || s[i] == '.')
            {
                // 一个单词解析结束
                if(!tmp.empty())
                {
                    countMap[tmp]++;
                }
                
                tmp.clear();
            }
            else
            {
                tmp += tolower(s[i]);
            }
        }
        
        for(auto& e : countMap)
        {
            cout << e.first << ":" << e.second << endl;
        }
    }
    return 0;
}