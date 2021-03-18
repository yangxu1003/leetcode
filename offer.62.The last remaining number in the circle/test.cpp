class Solution {
public:
    int lastRemaining(int n, int m) {
        int x = 0;
        // 最后一轮剩下2个人，所以从2开始反推
        for(int i = 2; i <= n; ++i)
        {
            x = (m + x) % i;
        }

        return x;
    }
};