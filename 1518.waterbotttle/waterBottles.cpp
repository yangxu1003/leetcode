class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int sum = numBottles;
        while (empty >= numExchange)
        {
            numBottles = empty / numExchange;//可兑换的瓶子
            sum += numBottles;//总数
            empty = empty % numExchange + numBottles;//空瓶子
        }

        return sum;
    }
};