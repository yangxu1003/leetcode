class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        //a��ASCIIֵΪ97��A��ASCIIֵΪ65��
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