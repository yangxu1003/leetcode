class Solution {
public:
    int cuttingRope(int n) {
        if(n < 4)
        {
            return n - 1;
        }

        long ret = 1;
        while(n >= 5)
        {
            ret *= 3;
            ret %= 1000000007;
            n -= 3;
        }

        // 最终剩下来的肯定是2,3,4
        return (int) (ret * n % 1000000007);
    }
};