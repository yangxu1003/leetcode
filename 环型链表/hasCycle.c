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
        //���ÿ���ָ��slow��fast
        ListNode* slow = head, * fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;//��ָ��ÿ����һ��
            fast = fast->next->next;//��ָ��ÿ��������

            if (fast == slow)
            {
                return true;
            }
        }

        return false;

    }
};