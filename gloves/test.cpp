class Gloves {
public:
    int findMinimum(int n, vector<int> left, vector<int> right) {
        //1.保证把一边的手套的每种都拿到
        //2.一边的手套为0时拿对面的
        int sumLeft = 0, sumRight = 0;
        int leftMin = INT_MAX, rightMin = INT_MAX;
        for(int i = 0; i < n; ++i)
        {
            if(left[i]*right[i] == 0)
            {
                sumLeft = sumLeft + left[i] + right[i];//把含零加上的双方都加上
                sumRight = sumRight + left[i] + right[i];
            }
            else
            {
                sumLeft += left[i];
                leftMin = min(leftMin, left[i]);
                sumRight += right[i];
                rightMin = min(rightMin, right[i]);
            }
        }
        
        sumLeft = sumLeft - leftMin + 1;//减去最小值+1
        sumRight = sumRight - rightMin + 1;
        return min(sumLeft, sumRight)+1;//加上对面的另外一个随机的
    }
};