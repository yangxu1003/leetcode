int pivotIndex(int* nums, int numsSize){
  int total = 0;
  //记数组的全部元素之和为total
  for (int i = 0; i < numsSize; ++i) 
  {
    total += nums[i];
  }

  int sum = 0;
  //左侧元素之和为sum,右侧为total-sum-num[i]。
  //当中心索引左侧或右侧没有元素时，即为零个项相加，这在数学上称作(空和)。在程序设计中我们约定(空和是零)。
  for (int i = 0; i < numsSize; ++i)
  {
    //左右相等为sum = total-sum-num[i],即2sum + num[i] = total 
    if (2 * sum + nums[i] == total) 
    {
      return i;
    }
    sum += nums[i];
  }

  return -1;
                  
}
