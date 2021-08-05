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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevLeft = dummy;
        prevLeft->next = head;

        int div = right - left;//提前存区间
        while(left > 1)
        {
            prevLeft = prevLeft->next; 
            left--;
        }
        
        //头插法
        ListNode* prev = prevLeft;
        ListNode* cur = prevLeft->next;
        while(div--)
        {
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy->next;
    }
};