struct Node* copyRandomList(struct Node* head) {
    if (head == NULL)
    {
        return NULL;
    }
    //1.拷贝节点，连接到每一个原节点的后边
    struct Node* cur = head;
    while (cur)
    {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->next = NULL;
        copy->val = cur->val;
        copy->random = NULL;

        struct Node* next = cur->next;
        cur->next = copy;
        copy->next = next;

        cur = next;
    }
    //2.拷贝原节点中的random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL)
        {
            copy->random = NULL;
        }
        else
        {
            copy->random = cur->random->next;
        }
        cur = copy->next;
    }

    //3.拆分出复制链表
    cur = head;
    struct Node* copyHead = head->next;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        cur->next = next;
        if (next)
        {
            copy->next = next->next;
        }
        else
        {
            copy->next = NULL;
        }
        cur = next;
    }
    return copyHead;
}