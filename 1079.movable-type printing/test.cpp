class Solution {
public:
    void dfs(string& tiles, string curStr, unordered_set<string>& hashset, vector<bool>& book)
    {
        if(!curStr.empty())
        {
            hashset.insert(curStr);//set天然去重
        }

        for(int i = 0; i < tiles.size(); ++i)
        {
            if(book[i] == false)
            {
                book[i] = true;
                dfs(tiles, curStr + tiles[i], hashset, book);

                book[i] = false;//回溯
            }
        }
    }
    
    int numTilePossibilities(string tiles) {
        unordered_set<string> hashset;
        vector<bool> book(tiles.size(), false);//标记使用过的
        dfs(tiles, "", hashset, book);

        return hashset.size();
    }
};