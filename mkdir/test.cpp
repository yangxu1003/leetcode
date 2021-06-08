#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        string s;
        set<string> set1;
        while(n--)
        {
            cin >> s;
            set1.insert(s);//存进set进行排序
        }
        
        vector<string> vs;//存进vector以便下标比较
        
        set<string>::iterator it = set1.begin();
        while(it != set1.end())
        {
            vs.push_back(*it);
            ++it;
        }
        
        vector<string> ret;
        size_t len = vs.size()-1;
        for(size_t i = 1; i <= len; ++i)
        {
            string tmp = vs[i-1];
            tmp += '/';
            if(vs[i].substr(0, tmp.size()) != tmp)
            {
                ret.push_back(vs[i-1]);
            }
        }
        ret.push_back(vs[len]);//插入最后一个
        
        for(size_t i = 0; i < ret.size(); ++i)
        {
            cout << "mkdir -p " << ret[i] << endl;
        }
        cout << endl;
    }
    return 0;
}