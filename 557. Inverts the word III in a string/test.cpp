class Solution {
public:
    string reverseWords(string s) {
        size_t pos = 0;
        int left = 0;//每次走的位置
        while((pos = s.find(' ', pos+1)) != string::npos)
        {
            reverse(s.begin()+left, s.begin()+pos);
            left = pos+1;
        }

        reverse(s.begin()+ left, s.end());

        return s;
    }
};