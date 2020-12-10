struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    //���������: fast->next == NULLʱ���� ż�������: fast == NULL����
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;//ÿ����һ��
        fast = fast->next->next;//ÿ��������
    }
    return slow;
}