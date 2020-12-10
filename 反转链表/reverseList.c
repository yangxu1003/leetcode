/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* prev = NULL, * cur = head; //prev������һ����㣬cur���浱ǰ���
    while (cur)
    {
        struct ListNode* next = cur->next;//����cur����һ�����
        cur->next = prev;//cur����ǰ���
        prev = cur;//ǰ������
        cur = next;//����
    }
    return prev;
}