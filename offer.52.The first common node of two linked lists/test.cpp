class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* A = headA;
        ListNode* B = headB;

        while(A != B)
        {
            A = (A != nullptr ? A->next : headB);//A走完完了去走B
            B = (B != nullptr ? B->next : headA);//B走完了取走A
        }

        return A;
    }
};