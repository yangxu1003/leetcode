int binarySearch(int* nums, int numsSize, int target, bool lower)
{
  int left = 0,right = numsSize-1,retIndex = numsSize;
  while(left <= right)
  {
    int middle = left + (right - left) / 2;
    if(nums[middle] > target || (lower && nums[middle] >= target))
    {
      right = middle - 1;
      retIndex = middle;                                                        
    }
    else
    {
      left = middle + 1;                                                                              
    }
                                        
  }

  return retIndex;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
  int leftIdx = binarySearch(nums, numsSize, target, true);//找第一个>=target的下标
  int rightIdx = binarySearch(nums, numsSize, target, false) - 1;//找第一个>target的下标

  int* ret = malloc(sizeof(int) * 2);
  *returnSize = 2;
  if (leftIdx <= rightIdx && rightIdx < numsSize ) 
  {
    ret[0] = leftIdx;
    ret[1] = rightIdx;
    return ret;                                            
  }

  ret[0] = -1, ret[1] = -1;
  return ret;

}
