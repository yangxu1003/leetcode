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
        if(head == nullptr){
            return nullptr;
        }

        //1.拷贝普通节点，连接到每一个原节点的后边
        Node* cur = head;
        while(cur != nullptr){
            Node* tmp = new Node(cur->val);//开新节点
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        //连接普通节点的random
        cur = head;
        while(cur != nullptr){
            Node* copy = cur->next;
            if(cur->random == nullptr){
                copy->random = nullptr;
            }
            else{
                copy->random = cur->random->next;
            }
            cur = copy->next;
        }

        //和原链表拆分
        cur = head;
        Node* copyhead = cur->next;//copy链表的头节点
        Node* copy = cur->next;
        while(cur != nullptr){
            cur->next = copy->next;
            if(cur->next == nullptr){
                break;
            }
            cur = cur->next;
            copy->next = cur->next;
            copy = copy->next;
        }

        return copyhead;
    }
};