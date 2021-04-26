#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> v;
    int A_i;
    for(int i = 0; i < n; ++i)
    {
        cin >> A_i;
        v.push_back(A_i);
    }
    
    int ret = 0;
    int len = v.size()-1;
    for(int i = 1; i < len; ++i)
    {
        //找出峰值
        if((v[i] > v[i-1] && v[i] > v[i+1]) || (v[i] < v[i-1] && v[i] < v[i+1]))
        {
            ret++;
            if(i != len-2)//至少要有两个数
            {
                i++;
            }
        }
    }
    cout << ++ret << endl;//加上剩下的
    
    return 0;
}