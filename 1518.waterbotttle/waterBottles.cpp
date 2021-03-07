class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int sum = numBottles;
        while (empty >= numExchange)
        {
            numBottles = empty / numExchange;//�ɶһ���ƿ��
            sum += numBottles;//����
            empty = empty % numExchange + numBottles;//��ƿ��
        }

        return sum;
    }
};