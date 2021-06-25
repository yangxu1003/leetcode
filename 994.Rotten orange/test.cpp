class Solution {
public:
    const int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;

        int row = grid.size();
        int col = grid[0].size();

        //1.将所有腐烂橘子入队
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
            }
        }

        int step = 0;//步数

        //2.进行传播
        while(!q.empty())
        {
            int n = q.size();
            int flag = 0;//标记是否感染, 0 表示未感染

            while(n--)
            {
                pair<int, int> cur = q.front();
                q.pop();
                
                //往四个方向蔓延
                for(int i = 0; i < 4; ++i)
                {
                    int nx = cur.first + direct[i][0];
                    int ny = cur.second + direct[i][1];
                    
                    //位置越界，或者空格，或者 已腐烂的橘子
                    if(nx < 0 || nx >= row || ny < 0 || ny >= col)
                    {
                        continue;
                    }

                    if(grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;//变为腐烂橘子 
                        q.push(make_pair(nx, ny));
                        flag = -1;//表示感染
                    }  
                }
            }
            if(flag == -1)
            {
                step++;
            }
        }


        //3.遍历判断是否还有新鲜
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; j < col; ++j)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return step;
    }
};