class Solution {
public:
    int numWays(int n) {
        int sum = 1;
        int n1 = 1, n2 = 1;
        for(int i = 2; i <= n; ++i)
        {
            sum = (n1 + n2) % 1000000007;
            n1 = n2;
            n2 = sum;
        }

        return sum;
    }    
};