int* sortedSquares(int* nums, int numsSize, int* returnSize){
  *returnSize = numsSize;
  int *sortArray = (int*)malloc(sizeof(int)*numsSize);
  
  //我们可以使用两个指针分别指向位置0和numsSize-1,选择较大的那个逆序放入并移动指针
  int index = numsSize-1;
  for(int i = 0,j = numsSize-1;i <= j;--index)
  {
    if(nums[i]*nums[i] > nums[j]*nums[j])
    {
      sortArray[index] = nums[i]*nums[i];
      ++i;                                             
    }
    else 
    {
      sortArray[index] = nums[j]*nums[j];
      --j;
    }
                             
  }
  
  return sortArray;
}
