/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val) {
    //判空结点和头指针的值
    while (head != NULL && head->val == val) {
        head = head->next;
    }
    struct ListNode* prev = NULL;//当前结点
    struct ListNode* cur = head;//删除结点的前一结点
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