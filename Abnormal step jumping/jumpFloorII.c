class Solution {
public:
    int jumpFloorII(int number) {
        if (number == 1)
        {
            return 1;
        }
        return jumpFloorII(number - 1) * 2;
    }
};