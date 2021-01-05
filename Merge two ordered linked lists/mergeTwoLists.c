/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* head = NULL,*tail = NULL;
    //���ڱ�λ��ͷ�ڵ㣬���洢��Ч���ݣ�����β��
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    //ȡС��β��
    while(l1 && l2)
    {
        //l1��valС�Ͱ�l1β���tail��Ȼ����tail����һ����㣬l1Ҳ����һ�����
        if(l1->val < l2->val)
        {
            tail->next = l1;
            l1 = l1->next;
            tail = tail->next;
        }
        else
        {
            tail->next = l2;
            l2 = l2->next;
            tail = tail->next;
        }
    }

    if(l1)
    {
        tail->next = l1;
    }
    else
    {
        tail->next = l2;
    }

    //����head��next
    struct ListNode* realHead = head->next;
    free(head);

    return realHead;

}