class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
        if(gifts.size() == 0)
        {
            return 0;
        }
        int ret;
        int count = 0;
        for(int i = 0; i < n; ++i)
        {
            if(count == 0)
            {
                ret = gifts[i];
                count++;
            }
            else
            {
                if(ret == gifts[i])
                {
                    count++;
                }
                else
                {
                    count--;
                }
            }
        }
        
        int size = 0;
        for(int i = 0; i < n; ++i)
        {
            if(gifts[i] == ret)
            {
                ++size;
            }
        }
        return (size > n / 2) ? ret : 0;
    }
};