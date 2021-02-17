int* plusOne(int* digits, int digitsSize, int* returnSize){
  int len = digitsSize-1;

  while(len >= 0)
  {
    if(digits[len]+1 == 10)
    {
      digits[len] = 0;
      --len;

    }
    else 
    {
      digits[len]++;
      break;                                                        
    }    

  }

  if(digits[0] != 0)
  {
    *returnSize = digitsSize;
    return digits;
  }

  *returnSize = digitsSize + 1;
  int* retArray = (int*)malloc(sizeof(int)*(*returnSize));
  retArray[0] = 1;

  memcpy(retArray+1, digits, sizeof(int)*digitsSize);
  return retArray;
}
