int thirdMax(int* nums, int numsSize){
  //由于题目没给范围，所以先将存储前三大的数的变量设置成最小值
  int max = INT_MIN,two = INT_MIN,three = INT_MIN,cnt = 1;
  //然后再用3个变量来判断数组中是否有三个不同的值(先将他们都赋值为数组第一个数)
  int temp1 = nums[0],temp2 = nums[0],temp3 = nums[0];

  //循环找到前三大的数
  for(int i = 0;i < numsSize;i++)
  {
    //这里我们要保证temp2和temp3都与temp1不相同
    if(nums[i] != temp1)
    {
      if(temp1 != temp2)
      {
        temp3 = nums[i];
      }
      else 
      {
        temp2 = nums[i];
      }                                
    }
    
    //如果找到一个更大的数，则将当前的max变成two，two变成three
    if(nums[i] > max)
    {
      three = two;
      two = max;
      max = nums[i];
    }
    else if(nums[i] < max && nums[i] > two)
    {
      three = two;
      two = nums[i];                                            
    }
    else if(nums[i] < two && nums[i] > three) 
    {
      three = nums[i];
    }
  }
  
  if(temp2 == temp3 || temp1 == temp3) 
  {
    return max;
  }   
      
  return three;
}
