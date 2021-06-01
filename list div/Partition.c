/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {

        //�ڱ���� lessHead��ű�xС�Ľ��
        struct ListNode* lessHead = NULL, * lessTail = NULL;
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        //greaterHead��ű�x��Ľ��
        struct ListNode* greaterHead = NULL, * greaterTail = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* cur = pHead;

        //��������
        while (cur)
        {
            //��С��x�Ľ��β���less,��������η���greater����
            if (cur->val < x)
            {
                lessTail->next = cur;
                lessTail = cur;
            }
            else
            {
                greaterTail->next = cur;
                greaterTail = cur;
            }
            cur = cur->next;
        }

        lessTail->next = greaterHead->next;//����������
        greaterTail->next = NULL;//β���
        struct ListNode* realHead = lessHead->next;
        free(lessHead);
        free(greaterHead);
        return realHead;
    }
};