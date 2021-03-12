#include <iostream>
#include <stdio.h>

using namespace std;

int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

void LeapYear(int year, int cal[])
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
    int year, days;
    while(scanf("%d %d",&year, &days) != EOF)
    {
        LeapYear(year, cal);//判断闰年
        
        int month = 0;
        while(days > cal[month])
        {
            days -= cal[month];
            month++;
        }
        
        printf("%04d-%02d-%02d\n", year, month, days);
    }
    
    return 0;
}