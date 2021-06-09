#include iostream
#include string
#include vector

using namespace std;

void dfs(int x, int y, vectorvectorchar& vv, int& count)
{
    count++;
    vv[x][y] = '#';
    
    if(x  0 && vv[x-1][y] == '.')
        dfs(x-1, y, vv, count);
    
    if(x+1  vv.size() && vv[x+1][y] == '.')
        dfs(x+1, y, vv, count);
    
    if(y  0 && vv[x][y-1] == '.')
        dfs(x, y-1, vv, count);
    
    if(y+1  vv[0].size() && vv[x][y+1] == '.')
        dfs(x, y+1, vv, count);
    
}

int main()
{
    int m, n;
    while(cin  m  n)
    {
        vectorvectorchar vv(m, vectorchar(n));
        int row, col;起始位置
        
        for(int i = 0; i  m; ++i)输入瓷砖矩阵
        {
            for(int j = 0; j  n; ++j)
            {
                cin  vv[i][j];
                
                if(vv[i][j] == '@')
                {
                    row = i;
                    col = j;
                }
            }
        }
        
        int count = 0;
        dfs(row, col, vv, count);
        
        cout  count  endl;
    }
    return 0;
}