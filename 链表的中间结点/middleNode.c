struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //奇数个结点: fast->next == NULL时结束 偶数个结点: fast == NULL结束
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;//每次走一步
        fast = fast->next->next;//每次走俩步
    }
    return slow;
}