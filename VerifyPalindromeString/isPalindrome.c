bool isPalindrome(char * s){
  int n = strlen(s);
  int left = 0,right = n -1;

  while(left < right)
  {
    while(left < right && !isalnum(s[left]))
    {
      ++left;
    }
    while(left < right && !isalnum(s[right]))
    {
      --right;
    }
    if(left < right && tolower(s[left]) != tolower(s[right]))
    {
      return false;
    }
    left++;
    --right;                                                        
  }

  return true;

}
