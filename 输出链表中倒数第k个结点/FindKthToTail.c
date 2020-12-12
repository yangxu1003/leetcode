/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

 /**
  *
  * @param pListHead ListNode��
  * @param k int����
  * @return ListNode��
  */
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    struct ListNode* slow = pListHead, * fast = pListHead;

    //fast�Ⱥ���k����㣬����֮���slow�ľ�������ʱk����㣬
    while (k)
    {
        if (fast)//k�п��ܴ��ڽ������������ж�fast�Ƿ�ΪNULL
        {
            fast = fast->next;
            k--;
        }
        else
            return NULL;
    }

    //Ȼ��fast��slowͬʱ���ƣ�ֱ��fast==NULLʱ��������ʱslow��λ������ʱ���ǵ�k�����
    while (fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}