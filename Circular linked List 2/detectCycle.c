/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //��������ָ��slow��fast
    struct ListNode* slow = head, * fast = head;


    //�ж��Ƿ��л�
    while (fast && fast->next)
    {
        slow = slow->next;//��ָ��ÿ����һ��
        fast = fast->next->next;//��ָ��ÿ��������


        if (fast == slow)
        {
            break;//��������
        }
    }


    if (fast == NULL || fast->next == NULL)//�ж��޻������
    {
        return NULL;
    }


    //�л�
    while (head != fast)//fast����slow�����Ľ���ߣ�head��ͷ��ʼ�ߣ�head��fast��������ǻ���ͷ���
    {
        head = head->next;
        fast = fast->next;
    }

    return head;


}