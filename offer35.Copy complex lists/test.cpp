/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* cur = head;

        map<Node*, Node*> map;

        while(cur)
        {
            Node* newNode = new Node(cur->val);
            map[cur] = newNode;
            cur = cur->next;
        }

        cur = head;
        Node* dummy = new Node(0);
        Node* tmp = dummy;
        
        while(cur)
        {
            tmp->next = map[cur];//链接新节点
            tmp = tmp->next;

            tmp->random = map[cur->random];//链接random  
            cur = cur->next;   
        }

        return dummy->next;
    }
};