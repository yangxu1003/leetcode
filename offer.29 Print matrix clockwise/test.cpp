class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }

        int up = 0,down = matrix.size()-1;//上下边界
        int left = 0,right = matrix[0].size()-1;

        while(true)
        {
            for(int i = left; i <= right;i++)//从左往右
            {
                ret.push_back(matrix[up][i]);
            }

            if(++up>down)
                break;

            for(int i = up; i <= down; ++i)//从上往下
            {
                ret.push_back(matrix[i][right]);
            }

            if(--right < left){
                break;
            }
            for(int i = right; i >= left; --i)//从右往左
            {
                ret.push_back(matrix[down][i]);
            }

            if(--down < up){
                break;
            }
               
            for(int i = down; i >= up; --i)//从下往上
            {
                ret.push_back(matrix[i][left]);
            }

            if(++left > right){
                break;
            }
                
        }

        return ret;
    }
};