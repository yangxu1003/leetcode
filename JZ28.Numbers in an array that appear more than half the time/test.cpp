class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty()){
            return 0;
        }
        int max = numbers[0],min = numbers[0];
        for(auto num : numbers){
            if(num > max){
                max = num;
            }
            if(num < min){
                min = num;
            }
        }
        
        int length = max-min+1;
        int* arr = new int[length]; //计数数组
        for(int j = 0; j < length; ++j){
            arr[j] = 0;
        }
        for(auto e : numbers){
            arr[e-min]++;
        }
        
        int count = numbers.size() / 2;
        int i = 0;
        for(; i < length; ++i){
            if(arr[i] > count){
                return i+min;
            }
        }
        
        return 0;
    }
};