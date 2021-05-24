#include <iostream>
#include <vector>

using namespace std;

int minDistance(const string& s1, const string& s2)
{
    if(s1.empty() || s2.empty())
    {
        return max(s1.size(), s2.size());
    }
    
    int len1 = s1.size();
    int len2 = s2.size();
    
    vector<vector<int>> f(len1+1, vector<int>(len2+1, 0));
    for(int i=0; i<=len1; ++i)
    {
        f[i][0] = i;
    }
    for(int i=0; i<=len2; ++i)
    {
        f[0][i] = i;
    }
    
    for(int i=1; i<=len1; ++i)
    {
        for(int j=1; j<=len2; ++j)
        {
            if(s1[i-1] == s2[j-1])
            {
                f[i][j] = 1 + min(f[i-1][j], f[i][j-1]);//增加或删除
                f[i][j] = min(f[i-1][j-1], f[i][j]);
            }
            else
            {
                f[i][j] = 1 + min(f[i-1][j], f[i][j-1]);//增加或删除
                f[i][j] = min(1+f[i-1][j-1], f[i][j]);//不相等距离加一
            }
        }
    }
    
    return f[len1][len2];
}

int main()
{
    string s1, s2;
    while(cin >> s1 >> s2)
    {
        cout << minDistance(s1, s2) << endl;
    }
    return 0;
}