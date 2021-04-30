class Solution {
public:
    int Add(int num1, int num2) {
        if(num1 == 0)
        {
            return num2;
        }
        if(num2 == 0)
        {
            return num1;
        }
        int a = num1 ^ num2;//当前非进位和
        int b = (num1 & num2) << 1;//求和后进位的数据
        
        return Add(a, b);
    }
};