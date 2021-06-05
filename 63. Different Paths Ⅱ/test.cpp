class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();  
        int n = obstacleGrid[0].size();  

        vector<vector<int>> dp(m, vector<int>(n, 0));

        //第 1 列的格子只有从其上边格子走过去这一种走法，因此初始化 dp[i][0] 值为 1，存在障碍物时为 0；
        for(int i = 0; i < m && obstacleGrid[i][0] == 0; ++i)
        {
            dp[i][0] = 1;
        }

        //第 1 行的格子只有从其左边格子走过去这一种走法，因此初始化 dp[0][j] 值为 1，存在障碍物时为 0。
        for(int j = 0; j < n && obstacleGrid[0][j] == 0; ++j)
        {
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }    
            }
        }

        return dp[m-1][n-1];  
    }
};