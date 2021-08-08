class Solution {
public:
    // 小根堆的回调函数
    struct cmp{  
       bool operator()(ListNode *a, ListNode *b){
          return a->val > b->val;
       }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> q;
        // 建立大小为k的小根堆
        for(auto& e : lists){
            if(e != nullptr)
            {
                q.push(e);
            } 
        }

        // 可以使用哑节点/哨兵节点
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        // 开始出队
        while(!q.empty()){
            ListNode* top = q.top();
            q.pop();
            cur->next = top;
            cur = top;
            if(top->next)
            {
                q.push(top->next);
            } 
        }
        return dummy->next;  
    }
};