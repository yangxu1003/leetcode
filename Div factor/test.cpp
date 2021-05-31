#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    int a;
    while(cin >> a)
    {
        string ret;
        ret += to_string(a);
        ret += " =";
        for(int i = 2; i <= sqrt(a); ++i)
        {
            while(a % i == 0)
            {
                ret += " ";
                ret += to_string(i);
                ret += " *";
                a /= i;
            }
        }
        
        if(a != 1)
        {
            ret += " ";
            ret += to_string(a);
        }
        else
        {
            ret.pop_back();
        }
        cout << ret << endl;
        ret.clear();
    }
    return 0;
}