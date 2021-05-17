#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getLuckNum(vector<int> &v, int n, int pos, int sum, int multi)
{
    int count = 0;
    for(int i = pos; i < n; ++i)
    {
        sum += v[i];
        multi *= v[i];
        if(sum > multi)
        {
            count += 1 + getLuckNum(v, n, i+1, sum, multi);
        }
        else if(v[i] == 1)
        {
            count += getLuckNum(v, n, i+1, sum, multi);
        }
        else
        {
            break;//回溯
        }
        
        sum -= v[i];
        multi /= v[i];
        
        //去重
        while(i < n - 1 && v[i] == v[i+1])
        {
            i++;
        }
    }
    
    return count;
}

int main()
{
    int n;
    while(cin >> n)
    {
        vector<int> v(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        cout << getLuckNum(v, n, 0, 0, 1) << endl;
    }
    return 0;
}