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
        if(head == nullptr)
        {
            return nullptr;
        }

        unordered_map<Node*, Node*> map;
        
        Node* cur = head;
        while(cur != nullptr)
        {
            Node* node = new Node(cur->val);
            map[cur] = node;
            cur = cur->next;
        }

        cur = head;
        Node* newNode = map[cur];
        while(cur != nullptr)
        {
            newNode->random = map[cur->random];
            
            cur = cur->next;
            newNode->next = map[cur];
            newNode = newNode->next;
        }

        return map[head];
    }
};