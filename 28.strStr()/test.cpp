class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)
        {
            return 0;
        }
        int m = haystack.size();
        int n = needle.size();
        for(int i = 0; i + n <= m; ++i)
        {
            int j = 0;
            for(; j < n; ++j)
            {
                if(haystack[i+j] != needle[j])
                {
                    break;
                }
            }

            if(j == n)
            {
                return i;
            }
        }

        return -1;
    }
};