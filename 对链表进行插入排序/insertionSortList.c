/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* sortHead = head;//排序的头节点
    Node* cur = head->next;
    sortHead->next = NULL;

    while (cur)
    {
        Node* next = cur->next;//保存cur的下一个节点
        //头插
        if (cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //中间插入
            Node* sortCur = sortHead->next;
            Node* sortPrev = sortHead;//防止sortHead改变，找不到头节点

            while (sortCur)
            {
                if (sortCur->val <= cur->val)
                {
                    sortPrev = sortCur;
                    sortCur = sortCur->next;
                }
                else
                {
                    sortPrev->next = cur;
                    cur->next = sortCur;
                    break;
                }
            }
            //尾插
            if (sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next = NULL;
            }
        }
        cur = next;
    }
    return sortHead;
}

