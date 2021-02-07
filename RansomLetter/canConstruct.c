bool canConstruct(char * ransomNote, char * magazine){
  int len1 = strlen(ransomNote);
  int len2 = strlen(magazine);

  int count[26];//创建一个计数数组来统计字符在magazine中出现的次数
  memset(count, 0, sizeof(int)*26);

  for(int i = 0; i < len2; ++i)
  {
    count[magazine[i] - 'a']++;
                    
  }

  //如果ransom的字符在计数数组count中的次数为0，就返回false
  for(int i = 0; i < len1; ++i)
  {
    if(count[ransomNote[i] - 'a'] == 0)
    {
      return false;                              
    }
    else
    {
      count[ransomNote[i] - 'a']--;
    }
                        
  }

    return true;

}
