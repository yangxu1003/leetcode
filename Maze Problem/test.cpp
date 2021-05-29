#include <iostream>
#include <vector>

using namespace std;

int ROW, COL;
vector<vector<int>> maze;//迷宫矩阵
vector<vector<int>> pathCur;//存当前路径
vector<vector<int>> pathMin;//最短路径

void mazeTrack(int i, int j)
{
    maze[i][j] = 1;
    pathCur.push_back({i, j});
    
    if(i == ROW-1 && j == COL-1)//终点
    {
        if(pathMin.empty() || pathMin.size() > pathCur.size())
        {
            pathMin = pathCur;
        }
    }
    
    //向右
    if(j < COL-1 && maze[i][j+1] == 0)
        mazeTrack(i, j+1);
    //向左
    if(j > 0 && maze[i][j-1] == 0)
        mazeTrack(i, j-1);
    //向上
    if(i > 0 && maze[i-1][j] == 0)
        mazeTrack(i-1, j);
    //向下
    if(i < ROW-1 && maze[i+1][j] == 0)
        mazeTrack(i+1, j);
    
    maze[i][j] = 0;//恢复矩阵
    pathCur.pop_back();
}

int main()
{
    while(cin >> ROW >> COL)
    {
        maze = vector<vector<int>>(ROW, vector<int>(COL, 0));//开辟迷宫矩阵
        pathCur.clear();
        pathMin.clear();
        for(int i = 0; i < ROW; ++i)
        {
            for(int j = 0; j < COL; ++j)
            {
                cin >> maze[i][j];
            }
        }
        
        mazeTrack(0, 0);//搜索路径
        
        for(int i = 0; i < pathMin.size(); ++i)
        {
            cout << "(" << pathMin[i][0] << "," << pathMin[i][1]  << ")"<< endl;
        }
    }
    
    return 0;
}