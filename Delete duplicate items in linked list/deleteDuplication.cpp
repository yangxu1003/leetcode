/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
        {
            return pHead;
        }

        ListNode* prev = NULL;
        ListNode* cur = pHead;
        ListNode* next = cur->next;

        while (next)
        {
            if (cur->val != next->val)
            {
                prev = cur;
                cur = next;
                next = next->next;
            }
            else
            {
                while (next && cur->val == next->val)
                {
                    next = next->next;
                }
                //判断prev是否为NULL
                if (prev == NULL)
                {
                    pHead = next;
                }
                else
                {
                    prev->next = next;
                }

                //释放掉重复结点
                while (cur != next)
                {
                    ListNode* temp = cur;
                    cur = cur->next;
                    free(temp);
                }

                if (next)
                {
                    next = next->next;
                }

            }
        }

        return pHead;
    }
};