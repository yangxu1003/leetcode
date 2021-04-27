class Finder {
public:
    int findElement(vector<int> A, int n, int x) {
        // write code here
        int left = 0, right = n-1;
        int middle;
        while(left <= right)
        {
            middle = left + (right - left) / 2;
            if(A[middle] == x)
            {
                return middle;
            }
            else if(A[middle] < x)
            {
                if(A[middle] < A[left] && A[right] < x)
                {
                    right = middle - 1;
                }
                else
                {
                    left =  middle+1;
                }
            }
            else
            {
                if(A[middle] > A[left] && A[left] > x)
                {
                    left = middle+1;
                }
                else
                {
                    right = middle-1;
                }
            }
        }
        
        return -1;
    }
};