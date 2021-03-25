class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        string ret = "0";
        //num1�����ӳ���num2��ÿһλ
        for (int i = num1.size() - 1; i >= 0; --i) {
            string tmp;
            int sum = 0;
            int add = 0;//��λ
            for (int j = num2.size() - 1; j >= 0; --j) {
                sum = add + (num1[i] - '0') * (num2[j] - '0');
                add = sum / 10;
                sum %= 10;
                tmp += (sum + '0');//�������
            }
            if (add != 0) {
                tmp += (add + '0');
            }

            reverse(tmp.begin(), tmp.end());//��ת

            //����һλ�⣬ÿ��һ��ĩβ�ӵ������һ��'0'
            for (int k = num1.size() - 1; k > i; --k) {
                tmp += '0';
            }

            ret = addStrings(ret, tmp);//�ַ������
        }
        return ret;
    }

    string addStrings(string& num1, string& num2) {
        int add = 0;//��λ
        int sum = 0;
        int end1 = num1.size() - 1, end2 = num2.size() - 1;
        string addret;
        while (end1 >= 0 || end2 >= 0)
        {
            if (end1 >= 0)
            {
                sum = num1[end1] - '0'; //ת������
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

            addret += (sum + '0');//ת���ַ�
        }

        if (add == 1)
        {
            addret += ('1');
        }
        reverse(addret.begin(), addret.end());
        return addret;
    }
};