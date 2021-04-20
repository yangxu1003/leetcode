#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    long n;
    cin >> n;
    vector<long> v1;
    long a_i;
    for(long i=0; i<3*n; ++i)
    {
        cin >> a_i;
        v1.push_back(a_i);
    }
    
    sort(v1.begin(), v1.end());
    long sum = 0;//统计水平值总和最大值
    for(long i=3*n-2; i>n-1; i-=2)
    {
        sum += v1[i];
    }
    cout << sum << endl;
    
    return 0;
}