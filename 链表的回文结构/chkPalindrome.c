/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {

        //�п�
        if (A == NULL)
        {
            return false;
        }
        //һ�����
        if (A->next == NULL)
        {
            return true;
        }
        //�������
        if (A->next->next == NULL)
        {
            if (A->val == (A->next)->val)
            {
                return true;
            }
            return false;
        }
        //�������ϵĽ��
        //���ҵ��м���
        struct ListNode* slow = A, * fast = A;
        while (fast->next && fast)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //��slow��Ľ������
        //prev , slow���浱ǰλ�� ,next
        slow = slow->next;
        struct ListNode* prev = NULL;
        while (slow != NULL)
        {
            struct ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        //������prev��Ϊ��벿�ֵ�ͷָ��

        //�Ƚ�
        while (A && prev)
        {
            if (A->val == prev->val)
            {
                A = A->next;
                prev = prev->next;
            }
            else
                return false;
        }

        return true;

    }
};