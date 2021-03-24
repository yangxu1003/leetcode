class Solution {
public:
    string reverseStr(string s, int k) {
        for(int i=0; i<s.size(); i+=(2*k))//i+2k步
        {
            //剩余字符>=k个，反转前k个字符
            if(i+k <= s.size())
            {   
                reverse(s.begin()+i, s.begin()+k+i);//k-i==k个字符
            }
            else
            {
                reverse(s.begin()+i, s.end());//当<k个，全部反转
            }
        }
        return s;
    }
};