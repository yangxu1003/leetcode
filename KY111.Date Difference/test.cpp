#include <iostream>
#include <stdio.h>
using namespace std;

int cal[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

void IsLeapYear(int year, int cal[])
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
    int d1, d2;
    int year1, month1, day1, year2, month2, day2;
    int sum = 1;
    while(scanf("%d%d", &d1, &d2) != EOF)
    {
        if(d1 > d2)//保证d1 < d2
        {
            int tmp = d1;
            d1 = d2;
            d2 = d1;
        }
        
        year1 = d1 / 10000;//年月日分配值
        month1 = d1 % 10000 / 100;
        day1 = d1 % 100; 
        year2 = d2 / 10000;
        month2 = d2 % 10000 / 100;
        day2 = d2 % 100; 
        
        //当年月日不相等时,一直加到相等
        while(year1 < year2 || month1 < month2 || day1 < day2)
        {
            day1++;//天数加一
            IsLeapYear(year1, cal);//判断是否闰年
            if(day1 == cal[month1]+1)//超过当前月份的天数后
            {
                month1++;
                day1 = 1;
            }
            
            if(month1 == 13)//超过月数后
            {
                year1++;
                month1 = 1;
                IsLeapYear(year1, cal);//判断是否闰年
            }
            sum++;
        }
        printf("%d\n",sum);
        
    }
    return 0;
}