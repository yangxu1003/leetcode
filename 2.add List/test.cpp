/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        int carry = 0;//进位

        while(l1 != nullptr || l2 != nullptr)
        {
            int sum = carry;
            carry = 0;
            if(l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            if(sum >= 10)
            {
                sum -= 10;
                carry = 1;
            }
            ListNode* cur = new ListNode(sum);
            prev->next = cur;
            prev = cur;
        }

        if(carry == 1)
        {
            ListNode* cur = new ListNode(1);
            prev->next = cur;
        }

        return dummy->next;
    }
};