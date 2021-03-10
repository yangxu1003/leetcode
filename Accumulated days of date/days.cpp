#include <iostream>
#include <stdio.h>
using namespace std;

void leapYear(int year, int month, int day, int cal[])
{
    
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        cal[2] = 29;
    }
    else
    {
        cal[2] = 28;
    }
}


int main()
{
    int m;
    cin >> m ;//样例个数
    
    int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int year, month , day, daysAdd;
    for(int i = 0; i < m; ++i)
    {
        cin >> year >> month >> day >> daysAdd;
        
        leapYear(year, month, day, cal);//判断是否闰年
        
        day += daysAdd;
        while(day > cal[month])
        {   
            day -= cal[month];
            month++;
            if(month > 13)
            {
                month = 1;
                year++;
                leapYear(year, month, day, cal);
            }
        }
        
        printf("%4d-%02d-%02d\n",year, month, day);
    }
    
    return 0;
}