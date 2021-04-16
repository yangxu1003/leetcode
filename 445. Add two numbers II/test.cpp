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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1;
        stack<int> st2;

        while(l1 != nullptr)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }

        int add = 0;//进位
        int n1,n2,sum;
        ListNode* prev = nullptr;
        while(!st1.empty() || !st2.empty() || add == 1)
        {
            if(!st1.empty())
            {
                n1 = st1.top();
                st1.pop();
            }
            else
            {
                n1 = 0;
            }

            if(!st2.empty())
            {
                n2 = st2.top();
                st2.pop();
            }
            else
            {
                n2 = 0;
            }

            sum = n1 + n2 + add;
            add = sum / 10;//进位
            sum %= 10;

            //头插法
            ListNode* newNode = new ListNode(sum);
            newNode->next = prev;
            prev = newNode;
        }
        return prev;
    }
};