int compress(char* chars, int charsSize){
  int i = 0,j = 0;
  int len = 0;//记录长度
  while(j < charsSize)
  {
    while( j < charsSize && chars[i] == chars[j] )
    {
      j++;
    }

    chars[len++] = chars[i];
    int times = j - i;//记录次数
    if(times == 1)
    {
      i = j;
      continue; 
    }

    if(times >= 10)
    {
      chars[len++] = times / 10 + '0';
      chars[len++] = times % 10 + '0';
    }
    else 
    {
      chars[len++] = times + '0';

    }

    i = j;                                                                            
  }
                  
  return len;
}
