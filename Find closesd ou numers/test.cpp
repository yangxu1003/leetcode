#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int i)//判断是否为素数
{
    for(int j = 2; j <= sqrt(i); ++j)
    {
        if(i % j == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    while(cin >> n)
    {
        //从中间开始寻找
        for(int i = n/2, j = n/2; i >= 2,j<=n; --i,++j)
        {
            if(isPrime(i) == true && isPrime(j) == true)
            {
                cout << i << endl;
                cout << j << endl;
                break;
            }
        }
    }
    return 0;
}