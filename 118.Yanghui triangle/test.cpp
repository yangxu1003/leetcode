class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        vv.resize(numRows, vector<int>());
        for(size_t i = 0; i < numRows; ++i)
        {
            vv[i].resize(i+1, 0);
            vv[i][0] = 1;
            vv[i][i] = 1;
        }

        for(size_t i = 0; i < vv.size(); ++i)
        {
            for(size_t j = 0; j < vv[i].size(); ++j)
            {
                if(vv[i][j] == 0)
                {
                    vv[i][j] = vv[i-1][j-1] + vv[i-1][j];                    
                }
            }
        }

        return vv;
    }
};