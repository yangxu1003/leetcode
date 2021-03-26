#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s;
    while(getline(cin, s))
    {
        int count[128] = {0};
        for(auto ch : s)
        {
            count[ch-'a']++;
        }
        int i = 0;
        for(; i < s.size(); ++i)
        {
            if(count[s[i]-'a'] == 1)
            {
                cout << s[i] << endl;
                break;
            }
        }
        
        if(i == s.size())
        {
            cout << -1 << endl;
        }
        
    }
    
    return 0;
}