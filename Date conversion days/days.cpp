#include <iostream>

using namespace std;

int main()
{
    int arr[13] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    int year, month, day;
    int outday;
    while(cin >> year >> month >> day)
    {
        outday = arr[month-1]+day;
        if (month > 2 && ((year%4 == 0 && year%100 != 0) || (year%400 == 0)))
        {
            outday++;
        }
        cout << outday << endl;
    }
    
    return 0;
}