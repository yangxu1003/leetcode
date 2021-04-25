class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
        {
            return 0;
        }
        
        int result = numbers[0];
        int times = 1;
        for(int i=1; i<numbers.size(); ++i)
        {
            if(times != 0)
            {
                if(numbers[i] == result)
                {
                    times++;
                }
                else
                {
                    times--;
                }
            }
            else
            {
                result = numbers[i];
                times = 1;
            }
        }
        
        //遍历数组
        times = 0;
        for(int i=0; i<numbers.size(); ++i)
        {
            if(numbers[i] == result)
            {
                times++;
            }
        }
        
        return times > numbers.size()/2 ? result : 0;
    }
};