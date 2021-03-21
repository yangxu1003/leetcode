class Solution {
public:
    string addStrings(string num1, string num2) {
        int add = 0;//进位
        int sum = 0;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        string addret;
        while (end1 >= 0 || end2 >= 0)
        {
            if (end1 >= 0)
            {
                sum = num1[end1] - '0'; //转成数字
                end1--;
            }
            else
            {
                sum = 0;
            }

            if (end2 >= 0)
            {
                sum = sum + (num2[end2] - '0');
                end2--;
            }

            sum += add;
            if (sum >= 10)
            {
                sum -= 10;
                add = 1;
            }
            else
            {
                add = 0;
            }

            addret += (sum + '0');//转成字符
        }

        if (add == 1)
        {
            addret += ('1');
        }
        reverse(addret.begin(), addret.end());
        return addret;
    }
};