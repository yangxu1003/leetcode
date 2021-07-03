class Solution {
public:
    bool isValid(int n, int x, int y, vector<pair<int, int>>book)
    {
        for(auto& i : book)
        {
            if(i.second == y || i.first + i.second == x + y || i.first - i.second == x - y)
            {
                return false;
            }
        }

        return true;
    }

    void dfs(int& ret, vector<string>& board, int n, int row, vector<pair<int, int>>book)
    {
        if(row == n)
        {
            ret++;
            return;
        }

        for(int j = 0; j < n; ++j)//当前行的列数
        {
            if(isValid(n, row, j, book))//判断位置是否有效
            {
                board[row][j] = 'Q';
                book.push_back(make_pair(row, j));
                dfs(ret, board, n, row+1, book);
                board[row][j] = '.';
                book.pop_back();
            }
        }
    }

    int totalNQueens(int n) {
        vector<pair<int, int>> book;//存皇后的坐标
        vector<string> board(n, string(n, '.'));//创建棋盘，并全初始化为.
        int ret = 0;
        dfs(ret, board, n, 0, book);
        return ret;
    }
};