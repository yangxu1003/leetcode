typedef char STDataType;

typedef struct Stack
{
    STDataType* _a;
    int _top; //ջ���±�
    int _capacity;
}Stack;

void StackInit(Stack* pst);
void StackDestory(Stack* pst);
void StackPush(Stack* pst, STDataType x);//��ջ
void StackPop(Stack* pst);//��ջ
int StackSize(Stack* pst);//��ȡ���ݸ���

//����1�ǿ�  ����0�Ƿǿ�
int StackEmpty(Stack* pst);

//��ȡջ��������
STDataType StackTop(Stack* pst);

void StackInit(Stack* pst)
{
    assert(pst);
    pst->_a = malloc(sizeof(STDataType) * 4);
    pst->_top = 0;
    pst->_capacity = 4;
}

void StackDestory(Stack* pst)
{
    assert(pst);
    free(pst->_a);
    pst->_a = NULL;
    pst->_top = pst->_capacity = 0;
}
void StackPush(Stack* pst, STDataType x)
{
    assert(pst);
    //�ռ䲻������
    if (pst->_top == pst->_capacity)
    {
        pst->_capacity *= 2;
        STDataType* temp = realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
        if (temp == NULL)
        {
            printf("�ڴ治��\n");
            exit(-1);
        }
        else
        {
            pst->_a = temp;
        }
    }

    pst->_a[pst->_top] = x;
    pst->_top++;
}

//��ջ
void StackPop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);

    --pst->_top;
}

//��ȡ���ݸ���
int StackSize(Stack* pst)
{
    assert(pst);
    return pst->_top;
}

//����1�ǿ�  ����0�Ƿǿ�
int StackEmpty(Stack* pst)
{
    assert(pst);

    //return pst->_top == 0 ? 1 : 0;
    return !pst->_top;
}

//��ȡջ��������
STDataType StackTop(Stack* pst)
{
    assert(pst);
    assert(pst->_top > 0);

    return pst->_a[pst->_top - 1];
}

bool isValid(char* s) {
    Stack st;
    StackInit(&st);
    bool ret;
    while (*s != '\0')
    {
        if (*s == '[' || *s == '(' || *s == '{')
        {
            StackPush(&st, *s);
            ++s;
        }
        else
        {
            if (StackEmpty(&st))
            {
                ret = false;
                break;
            }
            char top = StackTop(&st);
            if (*s == ']' && top != '[')
            {
                ret = false;
                break;
            }
            if (*s == '}' && top != '{')
            {
                ret = false;
                break;
            }
            if (*s == ')' && top != '(')
            {
                ret = false;
                break;
            }
            StackPop(&st);
            ++s;
        }
    }

    if (*s == '\0')
    {
        ret = StackEmpty(&st);
    }

    StackDestory(&st);
    return ret;
}