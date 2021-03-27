/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* fast = head;
        while(n >0)
        {
            fast = fast->next;
            --n;
        }
        
        ListNode* prev = dummy;
        ListNode* cur = prev->next;
        while(fast != nullptr)
        {
            fast = fast->next;
            prev = cur;
            cur = cur->next;
        }
        
        prev->next = cur->next;
        
        return dummy->next;
    }
};