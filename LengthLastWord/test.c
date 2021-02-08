int lengthOfLastWord(char * s)
{
  int len = strlen(s);
  int ret = 0;

  //从后往前遍历，略过空格，从第一个非空格开始计数。
  //再次遇到空格，并且ret > 0，则说明找到了一个单词，退出循环。
  for(int i = len - 1; i >= 0; --i)
  {
    if(s[i] != ' ')
    {
      ++ret;
    }
    else
    {
      if(ret > 0)
      {
        break;                                                      
      }
    }     
                        
  }

  return ret;
}
