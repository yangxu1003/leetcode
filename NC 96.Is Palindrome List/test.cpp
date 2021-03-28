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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        ListNode* slow = head;
        ListNode* fast = head;
        
        //1.找到中间节点
        while(fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        //2.反转后半部分
        ListNode* prev = nullptr;
        ListNode* cur = slow;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        //3.比较
        while(head != slow)
        {
            if(head->val != prev->val)
            {
                return false;
            }
            else
            {
                head = head->next;
                prev = prev->next;
            }
        }
        
        return true;
    }
};