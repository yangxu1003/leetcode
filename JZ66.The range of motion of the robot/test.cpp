class Solution {
public:
    int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//方向矩阵
    
    bool isvalid(int x, int y, int& threshold)
    {
        int sum = 0;
        while(x != 0)
        {
            sum += x % 10;
            x /= 10;
        }
        
        while(y != 0)
        {
            sum += y % 10;
            y /= 10;
        }
        
        if(sum > threshold)
        {
            return false;
        }
        else
        {
            return true;
        }
        
    }
    
    void dfs(int x, int y, int& threshold, int row, int col, vector<vector<bool>>& visited, int& ret)
    {
        visited[x][y] = false;//标记
        
        if(isvalid(x, y, threshold) == false)//判断是否>threshold
        {
            return;
        }
        
        ret++;//结果
        //四个方向遍历
        for(int i = 0; i < 4; ++i)
        {
            int newx = x + direct[i][0];
            int newy = y + direct[i][1];
            
            //位置越界||访问过
            if(newx < 0 || newx >= row || newy < 0 || newy >= col || visited[newx][newy] == false)
            {
                continue;
            }
            
            dfs(newx, newy, threshold, row, col, visited, ret);
        }
    }
    
    int movingCount(int threshold, int rows, int cols) {
        vector<vector<bool>> visited(rows, vector<bool>(cols, true));
        int ret = 0;
        dfs(0, 0, threshold, rows, cols, visited, ret);
        
        return ret;
    }
};