class Solution {
public:
    void dfs(unordered_set<string>& hash, string& s, int n, int idx, vector<bool>& book, string& path)
    {
        if(idx == n)
        {
            hash.insert(path);
            return;
        }

        for(int i = 0; i < n; ++i)
        {
            //没使用过
            if(book[i] == true)
            {
                book[i] = false;
                path.push_back(s[i]);
                dfs(hash, s, n, idx+1, book, path);
                book[i] = true;
                path.pop_back();
            }
        }
    }

    vector<string> permutation(string s) {
        unordered_set<string> hash;
        
        int n = s.size();
        vector<bool> book(n, true);
        string path;
        dfs(hash, s, n, 0, book, path);

        vector<string> ret;
        for(auto& e : hash)
        {
            ret.push_back(e);
        }

        return ret;
    }
};