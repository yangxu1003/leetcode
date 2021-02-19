char * addBinary(char * a, char * b){
  
  int carry = 0;  //进位

  int length = (strlen(a)>strlen(b)? strlen(a)+2:strlen(b)+2);

  char* result = (char*)malloc(sizeof(char)*length);    //开辟空间
  result[length-1] = '\0';

  for(int i = strlen(a)-1,j = strlen(b)-1,k = length -2; (i >=0)||(j >= 0); i--,j--,k--)
  {
    int sum = carry;
    sum += (i >= 0? a[i]-'0':0);
    sum += (j >= 0? b[j]-'0':0);

    carry = sum /2;
    result[k] = '0'+ sum % 2;
  }
                
  if(carry == 0)  //最后无进位，直接返回
    return result+1;    
  
  result[0] = '1';    //有进位，补一个最高位
  return result;

}
