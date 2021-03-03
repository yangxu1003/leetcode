class Solution {
  public:
    void reverseString(vector<char>& s) {
      int size=s.size();
      int begin = 0;
      int end = size-1;
      while(begin < end)
      {
        swap(s[begin++],s[end--]);

      }
                                          
    }

};
