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
    ListNode* sortList(ListNode* head) {
        return merge(head);
    }

    ListNode* merge(ListNode* head)//分开
    {
        if(head == nullptr || head->next == nullptr)//只有一个元素时返回
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr)//找到中间节点
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;//分开

        ListNode* left = merge(head);
        ListNode* right = merge(mid);

        return _mergeSort(left, right);
    }

    ListNode* _mergeSort(ListNode* left, ListNode* right)//合并
    {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while(left != nullptr && right != nullptr)
        {
            if(left->val <= right->val)
            {
                cur->next = left;
                left = left->next;
            }
            else
            {
                cur->next = right;
                right = right->next;  
            }

            cur = cur->next;
        }

        if(left != nullptr)
        {
            cur->next = left;
        }
        else
        {
            cur->next = right;
        }
        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};