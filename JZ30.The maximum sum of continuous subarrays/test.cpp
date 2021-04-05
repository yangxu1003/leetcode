class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = array[0];
        int maxSum = array[0];
        int size = array.size();
        for(int i=1;i<size;i++)
        {
            if(sum<0)
            {
                sum = array[i];
            }
            else
            {
                sum += array[i];
            }
            if(maxSum<sum)
            {
                maxSum = sum;
            }
        }
        
        return maxSum;
    
    }
};