class Solution {
public:
    /**
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            if(next == nullptr)
            {
                break;
            }
            
            if(cur->val != next->val)
            {
                prev = cur;
                cur = next;
            }
            else
            {
                while(next != nullptr && cur->val == next->val)
                {
                    next = next->next;
                }
                cur = next;
                prev->next = cur;
            }
        }
        
        return dummy->next;
    }
};