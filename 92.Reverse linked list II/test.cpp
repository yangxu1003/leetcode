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
        ListNode* node = new ListNode(-1);
        node->next = head;
        int div = right-left;//翻转个数
        ListNode* prev = node;//保存反转位置的前一个节点
        while(left > 1)
        {
            prev = prev->next;
            left--;
        }

        //穿针引线
        ListNode* cur = prev->next;
        ListNode* next = cur->next; 
        while(div > 0)
        {
            cur->next = next->next;
            next->next = prev->next;
            prev->next = next;
            next = cur->next;
            --div;
        }
       
        return node->next;
    }
};