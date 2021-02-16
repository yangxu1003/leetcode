int* sortArrayByParity(int* A, int ASize, int* returnSize){
  *returnSize = ASize;
  int* retArray = (int*)malloc(sizeof(int)*ASize);

  int end = ASize-1;
  int begin = 0;
  for(int i = 0; i < ASize; ++i)
  {
    if(A[i] % 2 == 0)
    {
      retArray[begin++] = A[i];
    }
    else 
    {
      retArray[end--] = A[i];
    }                                            
  }

  return retArray;
}
