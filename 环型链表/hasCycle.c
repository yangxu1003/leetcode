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
    bool hasCycle(ListNode* head) {
        //设置快慢指针slow，fast
        ListNode* slow = head, * fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;//慢指针每次走一步
            fast = fast->next->next;//快指针每次走俩步

            if (fast == slow)
            {
                return true;
            }
        }

        return false;

    }
};