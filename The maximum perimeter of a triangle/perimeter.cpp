class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(),A.end());
        for(size_t i = A.size()-1; i>=2; --i)
        {
            // a + b > c 是三角形面积不为0的条件
            if(A[i-1]+A[i-2] > A[i])
            {
                int C = A[i]+A[i-1]+A[i-2];
                return C; 
            }
        }
        return 0;
    }
};