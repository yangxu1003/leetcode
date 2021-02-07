bool isPalindrome(int x){
  // 特殊情况：当 x < 0 时，x 不是回文数。
  // 同样地，如果数字的最后一位是 0时，不是回文数，因为首位数不肯为0
  //只有 0 满足这一属性
  if (x < 0 || (x % 10 == 0 && x != 0)) 
  {
            return false;                
  }

  int revertNum = 0;
  while(x > revertNum)
  {
    revertNum = revertNum * 10 + x % 10;
    x /= 10;                        
  }

  // 当数字长度为奇数时，我们可以通过 revertedNumber/10 去除处于中位的数字。
  return x == revertNum || x == revertNum / 10;
}
