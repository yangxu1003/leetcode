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
    ListNode* Reverse(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* prev = nullptr;

        while(cur != nullptr)
        {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
        {
            return true;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rightHead = slow->next;
        slow->next = nullptr;
        rightHead = Reverse(rightHead);

        while(rightHead != nullptr)
        {
            if(rightHead->val != head->val)
            {
                return false;
            }
            rightHead = rightHead->next;
            head = head->next;
        }
        return true;
    }
};