/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* head = NULL,*tail = NULL;
    //带哨兵位的头节点，不存储有效数据，方便尾插
    head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    //取小的尾插
    while(l1 && l2)
    {
        //l1的val小就把l1尾插给tail，然后让tail后移一个结点，l1也后移一个结点
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

    //返回head的next
    struct ListNode* realHead = head->next;
    free(head);

    return realHead;

}