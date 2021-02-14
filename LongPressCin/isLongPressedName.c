bool isLongPressedName(char * name, char * typed){
  int n = strlen(name);
  int m = strlen(typed);
  int i = 0,j = 0;

  while(j < m)
  {
    //name[i]== typed[j]时,说明两个字符串存在一对匹配的字符，此时将i,j都加1
    if(name[i] == typed[j])
    {
      ++i;
      ++j;      
    }
    else if(j > 0 && typed[j] == typed[j-1])
    {
      //typed[j] == typed[j-1],说明存在一次长按键入，此时只将j加1。
      ++j;                    
    }
    else
    {
      return false;
    }
  }


  return i == n;
}
