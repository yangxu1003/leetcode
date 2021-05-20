#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    
    while(getline(cin, s))
    {
        int i;
        for(i = 0; i < s.size(); ++i)
        {
            if(s.find(s[i]) == s.rfind(s[i]))
            {
                cout << s[i] << endl;
                break;
            }
        }
        if( i == s.size())
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
