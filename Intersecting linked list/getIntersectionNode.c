//1.双指针法：让指针1遍历完链表1后指向链表2的第一个节点，
//指针2遍历完链表2后指向链表1的第一个节点。这样指针1遍历完链表2后，
//和指针2遍历完链表1后走过的总距离就是一样的，
//因此当两个指针都进入第二个链表后就可以保证它们离表尾的距离相同，
//就可以轻松判断是否相交了。
//2.链表的最后一个节点的next域通常是指向NULL的，
//指针在操作链表的时候也可以指向这个NULL（即指向最后一个节点还能->next），
//所以通常把这个NULL也理解为链表的一个节点来操作。比如在这里指针是指向NULL
//后再指向第二个表的第一个节点，如果不这样不相交的情况下就无法跳出循环。
//而且把这个NULL视为节点对于空链表情况也有利！！


struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {

    struct ListNode* A = headA;
    struct ListNode* B = headB;

    while (A != B)
    {
        if (A)
            A = A->next;
        else
            A = headB;
        if (B)
            B = B->next;
        else
            B = headA;
    }
    return B;
}