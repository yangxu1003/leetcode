class Solution {
public:
    void removeSpace(string &s)
    {
        int slow = 0,fast = 0;
        //删除开头空格
        while(s.size() > 0 && fast < s.size() && s[fast] == ' ')
        {
            fast++;
        }

        //删除中间多余空格
        for(;fast < s.size(); ++fast)
        {
            if(fast-1 > 0 && s[fast-1] == ' ' && s[fast] == ' ')
            {
                continue;
            }
            else
            {
                s[slow] = s[fast];
                slow++;
            }
        }

        //删除后面空格
        if(slow - 1 > 0 && s[slow-1] == ' ')
        {
            s.resize(slow-1); 
        }
        else
        {
            s.resize(slow);
        }
    }

    string reverseWords(string s) {
        removeSpace(s);//去掉多余空格
        reverse(s.begin(), s.end());//整体反转

        int left = 0;
        for(int right = 0; right < s.size(); ++right)//按按此反转
        {
            if(s[right] == ' ')
            {
                reverse(s.begin()+left, s.begin()+right);
                left = right+1;
            }
        }

        reverse(s.begin()+left, s.end());//反转剩余部分

        return s;
    }
};