#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main ()
{
    int n,m;
    while(cin>> n >> m)
    {
        vector<int> step(m+1, INT_MAX);//开m+1个空间，INT_MAX表示不能到达
        step[n] = 0;//step存的步数
        
        for(int i = n;i <= m; ++i)//石板坐标i
        {
            if(step[i] == INT_MAX)//没法到达
            {
                continue;
            }
            for(int j = 2;(j*j) <= i; ++j)//约数j
            {
                if(i % j == 0)
                {
                    if(i+j <= m)
                    {
                        step[i+j] = min(step[i]+1, step[i+j]);//选出到达当前石板的最小步数
                    }
                    if(i+(i/j) <= m)
                    {
                        step[i+(i/j)] = min(step[i]+1, step[i+(i/j)]);
                    }
                }
            }
        }
        
        if(step[m] == INT_MAX)//无法到达
        {
            step[m] = -1;
        }
        cout << step[m] << endl;
    }
    
    return 0;
}