#include <iostream>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        int month1 = 1;//成熟度为1个月
        int month2 = 0;//成熟度为2个月
        int month3 = 0;//成熟度为3个月以上
        
        while(n > 1)//一开始就一个月
        {
            month3 += month2;
            month2 = month1;
            month1 = month3;
            n--;
        }
        cout << month1 + month2+month3 << endl;
    }
    
    return 0;
}