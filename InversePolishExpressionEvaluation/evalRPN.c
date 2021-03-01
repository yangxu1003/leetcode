typedef int STDataType;
typedef struct Stack
{  
  STDataType* _a;
  int _top; //栈顶下标
  int _capacity;//容量
}Stack;
void StackInit(Stack* pst)
{
    pst->_a = malloc(sizeof(STDataType) * 4);
      pst->_top = 0;
        pst->_capacity = 4;

}
void StackPush(Stack* pst, STDataType x)
{
    if (pst->_top == pst->_capacity)
    {
          //增容
              pst->_capacity *= 2;
                  STDataType* temp = realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
                      pst->_a = temp;
          
                
    }
      //数据入栈
        pst->_a[pst->_top] = x;
         pst->_top++;
      
}
void StackPop(Stack* pst)
{
    assert(pst);
      assert(pst->_top > 0);

        --pst->_top;

}
STDataType StackTop(Stack* pst)
{
    assert(pst);
      assert(pst->_top > 0);
        
        return pst->_a[pst->_top - 1];

}

int evalRPN(char ** tokens, int tokensSize){
      Stack obj;
          StackInit(&obj);
              int x, y;
              for (int i = 0; i < tokensSize; i++) {
                if (!strcmp(tokens[i], "+")) {
                              x = StackTop(&obj); StackPop(&obj);//如果是运算符，取两次栈顶，计算，并将结果入栈
                                          y = StackTop(&obj); StackPop(&obj);
                                                      StackPush(&obj, y + x);
                                                              
                }
                else if(!strcmp(tokens[i], "-")) {
                              x = StackTop(&obj); StackPop(&obj);
                                          y = StackTop(&obj); StackPop(&obj);
                                                      StackPush(&obj, y - x);
                                                              
                }
                else if(!strcmp(tokens[i], "*")) {
                             x = StackTop(&obj); StackPop(&obj);
                                         y = StackTop(&obj); StackPop(&obj);
                                                     StackPush(&obj, y * x);
                                                             
                }
                else if(!strcmp(tokens[i], "/")) {
                              x = StackTop(&obj); StackPop(&obj);
                                          y = StackTop(&obj); StackPop(&obj);
                                                      StackPush(&obj, y / x);
                                                              
                }
                else {
                             StackPush(&obj, atoi(tokens[i]));//子字符串为操作数，将其化为整型并入栈
                                     
                }
                    
              }
                  return StackTop(&obj);

}
