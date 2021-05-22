#include <iostream>
#include <string>

using namespace std;

bool match(const char *pattern, const char *str)
{
    if(*pattern == '\0' && *str == '\0')
        return true;
    if(*pattern == '\0' || *str == '\0')
        return false;
    
    if(*pattern == '?')//1个
        return match(pattern+1, str+1);
    else if(*pattern == '*')//3种情况 0 1 多
        return match(pattern+1, str) || match(pattern+1, str+1) || match(pattern, str+1);
    else if(*pattern == *str)
        return match(pattern+1, str+1);
    else
        return false;//不相等
}

int main()
{
    string pattern, str;
    while(cin >> pattern >> str)
    {
        bool ret = match(pattern.c_str(), str.c_str());
        if(ret)
        {
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }
    return 0;
}