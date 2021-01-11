/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    //创建快慢指针slow，fast
    struct ListNode* slow = head, * fast = head;


    //判断是否有环
    while (fast && fast->next)
    {
        slow = slow->next;//慢指针每次走一步
        fast = fast->next->next;//快指针每次走俩步


        if (fast == slow)
        {
            break;//相遇跳出
        }
    }


    if (fast == NULL || fast->next == NULL)//判断无环的情况
    {
        return NULL;
    }


    //有环
    while (head != fast)//fast从与slow相遇的结点走，head从头开始走，head与fast相遇点就是环的头结点
    {
        head = head->next;
        fast = fast->next;
    }

    return head;


}