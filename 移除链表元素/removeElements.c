/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val) {
    //�пս���ͷָ���ֵ
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    struct ListNode* prev = NULL;//��ǰ���
    struct ListNode* cur = head;//ɾ������ǰһ���
    while (cur != NULL)
    {
        if (cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }
        else
        {
            cur = cur->next;
            prev->next = cur;
        }
    }

    return head;
}