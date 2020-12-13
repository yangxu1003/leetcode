/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {

        //哨兵结点 lessHead存放比x小的结点
        struct ListNode* lessHead = NULL, * lessTail = NULL;
        lessHead = lessTail = (struct ListNode*)malloc(sizeof(struct ListNode));
        //greaterHead存放比x大的结点
        struct ListNode* greaterHead = NULL, * greaterTail = NULL;
        greaterHead = greaterTail = (struct ListNode*)malloc(sizeof(struct ListNode));

        struct ListNode* cur = pHead;

        //遍历链表
        while (cur)
        {
            //把小于x的结点尾插进less,其余的依次放入greater里面
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

        lessTail->next = greaterHead->next;//连接俩链表
        greaterTail->next = NULL;//尾结点
        struct ListNode* realHead = lessHead->next;
        free(lessHead);
        free(greaterHead);
        return realHead;
    }
};