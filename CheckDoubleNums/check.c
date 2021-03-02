bool checkIfExist(int* arr, int arrSize){
  for(int i = 0; i < arrSize; ++i)
  {
    int j = i + 1;
    while(j<arrSize)
    {
      if(arr[i] / 2 == arr[j] && arr[i] % 2 == 0)
      {
        return true;
                                    
      }
      if(arr[i] * 2 == arr[j])
      {
        return true;
                                    
      }
      ++j;
    }

  }

  return false;
}
