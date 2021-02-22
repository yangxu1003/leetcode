int findUnsortedSubarray(int* nums, int numsSize){
  int max = nums[0];
  int min = nums[numsSize-1];

  int end = -1, begin = 0;

  for(int i = 0; i < numsSize; ++i)
  {
    if(nums[i] < max)
    {
      end = i;                                            
    }
    else 
    {
      max = nums[i];//维护左区间的max
                                                          
    }

    if(nums[numsSize-i-1] > min)
    {
      begin = numsSize-i-1;//                                                          
    }
    else 
    {
      min = nums[numsSize-i-1];//维护逆序遍历的右区间的min
                                                                      
    }
                                                        
  }

  return end - begin + 1;

}
