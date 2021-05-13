#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    const string s = "345678910JQKA2jokerJOKER";
    while(getline(cin, str))
    {
        if(str.find("joker JOKER") != string::npos)//王炸最大
        {
            cout << "joker JOKER" << endl;//找到直接输出
        }
        else
        {
            //分牌
            size_t pos = str.find('-');
            string str1 = str.substr(0, pos);
            string str2 = str.substr(pos + 1);
            ///这里有个坑就是 "10"是两位数，所以只能找空格
            //空格+1等于牌数
            int count1 = count(str1.begin(), str1.end(), ' ') + 1;
            int count2 = count(str2.begin(), str2.end(), ' ') + 1;
            if(count1 == count2)
            {
                //只要牌数相等，则第一张牌大的即为大
                if(s.find(str1[0]) > s.find(str2[0]))
                {
                    cout << str1 << endl;
                }
                else
                {
                    cout << str2 << endl;
                }
            }
            else
            {
                //牌数不相同，说明类型不同,只有炸弹可以和其它牌比较
                //其它类型都是错误的
                if(count1 == 4)//炸弹
                {
                    cout << str1 << endl;
                }
                else if(count2 == 4)
                {
                    cout << str2 << endl;
                }
                else
                {
                    cout << "ERROR" << endl;
                }
            }
            
        }
    }
    return 0;
}
