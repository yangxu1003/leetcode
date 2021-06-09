#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, k;
    int x, y;
    while(cin >> n >> m >> k)
    {
        vector<vector<double>> dp(n+1, vector<double>(m+1, 0));
        for(int i = 0; i < k; ++i)
        {
            cin >> x >> y;
            dp[x][y] = -1;//-1表示蘑菇
        }
        
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(i == 1 && j == 1)
                {
                    dp[i][j] = 1.0;
                }
                else if(dp[i][j] == -1)//有蘑菇
                {
                    dp[i][j] = 0;
                }
                else
                {
                    //dp[i][j] = dp[i-1][j]*下一步的概率+dp[i][j-1]*下一步的概率
                    dp[i][j] = dp[i-1][j]*(j == m ? 1 : 0.5) + dp[i][j-1]*(i == n ? 1 : 0.5);
                }
            }
        }
        
        printf("%0.2f\n", dp[n][m]);
    }
    return 0;
}