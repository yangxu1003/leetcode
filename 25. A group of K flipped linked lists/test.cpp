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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* cur = prev->next;
        ListNode* next;

        ListNode* tail = cur;//判断区间

        int count = k-1;
        while(cur != nullptr){
            //判断节点数是否满足k个
            for(int i = 1; i < k; ++i){
                if(tail == nullptr){
                    break;
                }
                tail = tail->next;
            }

            if(tail == nullptr){
                break;
            }
            
            count = k-1;

            //头插法反转k个元素
            while(count > 0){
                next = cur->next;
                cur->next = next->next;
                next->next = prev->next;
                prev->next = next;
                count--;
            }
            next = cur->next;
            prev = cur;
            cur = next;

            tail = cur;//头插tail相对位置改变，重新赋给cur
        }

        return dummy->next;
    }
};