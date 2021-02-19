int myAtoi(char * s){
  int i = 0;
  int flag = 1;//判断符号
  long retNumber = 0;
                  
  while(s[i] == ' ')//判断空格
  {
    i++;                            
  }

  if(s[i] == '-' || s[i] == '+')//判断正负号
  {
    flag = 44 - s[i++];                                
  }

  while(s[i] >= '0' && s[i] <= '9')//转换数字
  {
    retNumber = retNumber*10 + s[i] - '0';
    if(retNumber != (int)retNumber)//判断溢出
    {
      return (flag == 1) ? INT_MAX:INT_MIN;

    }
    
    i++;
  }

  retNumber *= flag;
  return retNumber;

}
