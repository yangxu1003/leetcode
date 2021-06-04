#include<iostream>
#include<cmath>
using namespace std;
//1.概率：n个人取到的不是自己名字的序列个数/n个人可能抽取的所有可能性
long long NotSelf(int n)
{
    if (n == 1 )
        return 0;
    if (n == 2)
        return 1;
    return (n - 1) * (NotSelf(n - 1) + NotSelf(n - 2));
}
long long Count(int n)
{
    double s = 1;
    while(n > 1)
    {
        s *= n;
        n--;
    }
    
    return s;
}

int main()
{
    int n;
    while (cin >> n)
    {
        double ret = (double)NotSelf(n)/Count(n);         //计算概率
        printf("%4.2f%%\n", ret * 100);
    }
    return 0;
}