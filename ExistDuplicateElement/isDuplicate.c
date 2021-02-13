bool containsDuplicate(int* nums, int numsSize){
  if(numsSize == 0)
  {
    return false;
  }
  int max = nums[0];
  int min = nums[0];
  for(int i = 0; i < numsSize; ++i)
  {
    if(nums[i] < min)
    {
      min = nums[i];
    }
    if(nums[i] > max)
    {
      max = nums[i];
    }
  }

  //利用计数排序的思想，创建一个计数数组来统计元素出现的次数
  int len = max - min + 1;
  int* count = (int*)malloc(sizeof(int) * len);
  memset(count, 0, sizeof(int)*len);

  for(int i = 0; i < numsSize; ++i)
  {
    count[nums[i] - min]++;
    if(count[nums[i] - min] > 1)
    {
      return true;
    }
  }

  return false;
}
