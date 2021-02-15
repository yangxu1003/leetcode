char * reverseOnlyLetters(char * S){
  int left = 0;
  int right = strlen(S)-1;

  while(left <= right)
  {
    //左右指针指向的字符都是字母，则交换左右指针的指向
    if(isalpha(S[left]) && isalpha(S[right]))
    {
      char tmp = S[left];
      S[left++] = S[right];
      S[right--] = tmp;                                                    
    }
    else if(isalpha(S[left]) == 0)
    {
      ++left;
    }
    else if(isalpha(S[right]) == 0)
    {
      --right;                                           
    }
  }

  return S;
}
