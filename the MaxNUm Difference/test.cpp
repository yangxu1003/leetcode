class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        int maxNum = A[0];
        
        for(int i = 1;i < n; ++i)
        {
            if(A[i] > maxNum)
            {
                maxNum = A[i];
            }
        }
        
        int minNum = min(A[0], A[n-1]);
        return maxNum-minNum;
    }
};