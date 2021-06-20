class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.empty())
        {
            return 0;
        }
        
        int row = triangle.size();
        
        vector<vector<int>> minSum(triangle);
        for(int i = row-2; i >= 0; --i)
        {
            for(int j = 0; j <= i; ++j)
            {
                minSum[i][j] = min(minSum[i+1][j+1], minSum[i+1][j]) + triangle[i][j];
            }
        }
        
        return minSum[0][0];
    }
};