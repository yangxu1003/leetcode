class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        //a的ASCII值为97，A的ASCII值为65。
        for (int i = 0; i < len; ++i)
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
        }

        return str;
    }
};