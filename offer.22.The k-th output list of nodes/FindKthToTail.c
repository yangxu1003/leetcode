/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode类
  * @param k int整型
  * @return ListNode类
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* slow = pListHead, * fast = pListHead;

    //fast先后移k个结点，移完之后和slow的距离正好时k个结点，
    while (k)
    {
        if (fast)//k有可能大于结点个数，这里判断fast是否为NULL
        {
            fast = fast->next;
            k--;
        }
        else
            return NULL;
    }

    //然后fast和slow同时后移，直到fast==NULL时结束，此时slow的位置正好时倒是第k个结点
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}