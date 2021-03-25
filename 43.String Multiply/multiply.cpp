class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ret = "0";
        //num1的数子乘以num2的每一位
        for (int i = num1.size() - 1; i >= 0; --i) {
            string tmp;
            int sum = 0;
            int add = 0;//进位
            for (int j = num2.size() - 1; j >= 0; --j) {
                sum = add + (num1[i] - '0') * (num2[j] - '0');
                add = sum / 10;
                sum %= 10;
                tmp += (sum + '0');//逆序存入
            }
            if (add != 0) {
                tmp += (add + '0');
            }

            reverse(tmp.begin(), tmp.end());//翻转

            //除第一位外，每乘一次末尾加递增多加一次'0'
            for (int k = num1.size() - 1; k > i; --k) {
                tmp += '0';
            }

            ret = addStrings(ret, tmp);//字符串相加
        }
        return ret;
    }

    string addStrings(string& num1, string& num2) {
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