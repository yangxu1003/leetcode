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

    Node* sortHead = head;//�����ͷ�ڵ�
    Node* cur = head->next;
    sortHead->next = NULL;

    while (cur)
    {
        Node* next = cur->next;//����cur����һ���ڵ�
        //ͷ��
        if (cur->val <= sortHead->val)
        {
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //�м����
            Node* sortCur = sortHead->next;
            Node* sortPrev = sortHead;//��ֹsortHead�ı䣬�Ҳ���ͷ�ڵ�

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
            //β��
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

