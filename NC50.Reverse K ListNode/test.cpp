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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* cur = prev->next;
        
        ListNode* tail = cur;//提前保存每次翻转的尾节点
        
        while(cur != nullptr)
        {
            for(int i = 1; i < k; ++i)//判断是否可以翻转
            {
                if(tail == nullptr)
                {
                    break;
                }
                tail = tail->next;
            }
            
            if(tail == nullptr)
            {
                break;
            }
            
            for(int i = 0; i < k - 1; ++i)//k个节点翻转k-1次
            {
                ListNode* next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
            }
            
            prev = cur;
            cur = cur->next;
            
            tail = cur;//重新赋值
        }
        
        ListNode* newHead = dummy->next;
        delete dummy;
        
        return newHead;
    }
};