#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Pos
{
    int x;
    int y;
    int level;//表示层数/步数
};

int bfs(vector<string>& map, int row, int col)
{
    //方向数组，下右左上
    int direct[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    queue<Pos> q;
    Pos start = {0, 1, 0}, end = {9, 8, 0};//入口出口
    q.push(start);//入口传入
    
    vector<vector<bool>> flag(row, vector<bool>(col, false));
    while(!q.empty())
    {
        Pos cur = q.front();
        q.pop();
        
        flag[cur.x][cur.y] = true;//表示遍历过
        
        //如果cur已经在出口的位置，说明最短路径已经找到
        if(cur.x == end.x && cur.y == end.y)
        {
            return cur.level;
        }
        
        //继续遍历cur的四个方向
        Pos next;
        for(int i = 0; i < 4; ++i)
        {
            next.x = cur.x + direct[i][0];
            next.y = cur.y + direct[i][1];
            
            //检测位置的坐标是否合法
            //检测位置的坐标是否通路
            //检测是否遍历过
            if(next.x >= 0 && next.x < row && next.y >= 0 && next.y < col\
               && map[next.x][next.y] == '.' && !flag[next.x][next.y])
            {
                next.level = cur.level + 1;
                q.push(next);
            }
        }
    }
    
    return 0;
}

int main()
{
    vector<string> map(10);//地图
    int i = 0;
    while(cin >> map[i++])
    {
        if(10 == i)
        {
            //已经将地图的数据接受完
            cout << bfs(map, 10, 10) << endl;
            i = 0;
        }
    }
    return 0;
}