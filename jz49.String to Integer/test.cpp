class Solution {
public:
    int StrToInt(string str) {
        if(str.size() == 0)
        {
            return 0;
        }
        
        int sum = 0;
        int flag = 1;
        for(int i = 0; i < str.size(); ++i)
        {
            if(i == 0 && (str[i] == '-'))
            {
                flag = -1;
                continue;
            }
            if(i == 0 && (str[i] == '+'))
            {
                flag = 1;
                continue;
            }
            if(str[0] == '0')
            {
                return 0;
            }
            if(str[i] <= '9' && str[i] >= '0')
            {
                sum = sum*10 + str[i]-48;
            }
            else
            {
                return 0;
            }
        }
        
        if(flag == 1)
        {
            return sum;
        }
        return -sum;
    }
};