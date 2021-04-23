class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return {};
        }

        vector<int> v;

        int row = matrix.size()-1;//行数的下标
        int column = matrix[0].size()-1; //列数的下标

        int startX = 0;//开始的横坐标
        int startY = 0;//纵坐标

        int x,y;
        while(startX <= row && startY <= column)
        {

            for(y=startY; y<=column; ++y)//top从左往右
            {
                v.push_back(matrix[startX][y]);//行不变
            }
            
            for(x=startX+1; x<=row; ++x)//top+1从上往下
            {
                v.push_back(matrix[x][column]);//列不动
            }

            if(startX < row && startY < column){
                for(int y=column-1; y>startY; --y)//从右往左
                {
                    v.push_back(matrix[row][y]);//行不变
                }

                for(int x=row; x>startX; --x)//从下往上
                {
                    v.push_back(matrix[x][startY]);//列不变                
                }
            }
            

            startX++;
            startY++;
            row--;
            column--;
        }

        return v;
    }
};