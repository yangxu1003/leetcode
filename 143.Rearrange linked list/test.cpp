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
    ListNode* midNode(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseRight(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void mergeList(ListNode* left, ListNode* right)
    {
        ListNode* leftnext; 
        ListNode* rightnext;
        while(left != nullptr && right != nullptr)
        {
            leftnext = left->next;
            rightnext = right->next;

            left->next = right;
            left = leftnext;

            right->next = left;
            right = rightnext;
        }
    }

    void reorderList(ListNode* head) {
        if(head == nullptr)
        {
            return;
        }
        
        ListNode* leftHead = head;
        ListNode* middle = midNode(head);//找到中间节点
        ListNode* rightHead = middle->next;//右半节点的头节点
        middle->next = nullptr;

        rightHead = reverseRight(rightHead);//反转右半部分，接收新的头节点

        mergeList(leftHead, rightHead);
    }
};