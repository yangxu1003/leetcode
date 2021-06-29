class Solution {
public:
    bool isValid(vector<string>& board, int x, int y, vector<pair<int, int>>& book)
    {   
        for(auto& e: book)
        {
            if(e.second == y || e.first - e.second == x - y || e.first + e.second == x + y)
            {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<string>>& ret, vector<string>& board, int n, int row, vector<pair<int, int>>& book)
    {
        if(row == n)
        {
            ret.push_back(board);
            return;
        }
        
        for(int j = 0; j < n; ++j)//当前行的列数
        {
            if(isValid(board, row, j, book))//判断是否可以放皇后
            {
                board[row][j] = 'Q';
                book.push_back(make_pair(row, j));
                dfs(ret, board, n, row+1, book);//走下一行
                board[row][j] = '.';
                book.pop_back();
            }   
        }
        
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ret;
        vector<pair<int, int>> book;
        vector<string> board(n, string(n, '.'));//创建棋盘，并全初始化为.

        dfs(ret, board, n, 0, book);
        return ret;
    }
};