#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        vector<string> vs;//存字符串
        int count = 0;//计数
        for(size_t i = 0;i < s.size(); ++i)
        {
            string tmp;//存参数字符串
            if(s[i] == '"')//解析带'
            {
                count++;
                i++;
                while(i < s.size() && s[i] != '"')
                {
                    tmp += s[i];
                    i++;
                }
                vs.push_back(tmp);
                tmp.clear();//清空
            }
            else if(s[i] != ' ')
            {
                count++;
                while(i < s.size() && s[i] != ' ')//走到空格停下
                {
                    tmp += s[i];
                    i++;
                }
                vs.push_back(tmp);
                tmp.clear();
            }
        }
        
        cout << count << endl;
        for(size_t i = 0; i < vs.size(); ++i)
        {
            cout << vs[i] << endl;
        }
    }
    return 0;
}