/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode* prev = NULL, * cur = head; //prev保存上一个结点，cur保存当前结点
    while (cur)
    {
        struct ListNode* next = cur->next;//保存cur的下一个结点
        cur->next = prev;//cur链向前结点
        prev = cur;//前结点后移
        cur = next;//后移
    }
    return prev;
}