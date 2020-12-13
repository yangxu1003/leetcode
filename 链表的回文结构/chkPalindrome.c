/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {

        //判空
        if (A == NULL)
        {
            return false;
        }
        //一个结点
        if (A->next == NULL)
        {
            return true;
        }
        //俩个结点
        if (A->next->next == NULL)
        {
            if (A->val == (A->next)->val)
            {
                return true;
            }
            return false;
        }
        //俩个以上的结点
        //先找到中间结点
        struct ListNode* slow = A, * fast = A;
        while (fast->next && fast)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //把slow后的结点逆置
        //prev , slow保存当前位置 ,next
        slow = slow->next;
        struct ListNode* prev = NULL;
        while (slow != NULL)
        {
            struct ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        //逆置完prev成为后半部分的头指针

        //比较
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