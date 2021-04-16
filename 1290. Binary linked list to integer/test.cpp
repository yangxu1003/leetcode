/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* cur = head;

        int ret = 0;
        while(cur != nullptr)
        {
            ret <<= 1;
            ret += cur->val;
            cur = cur->next;
        }

        return ret;
    }
};