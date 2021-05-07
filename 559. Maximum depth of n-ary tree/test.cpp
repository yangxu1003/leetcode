/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> q;
        if(root != nullptr)
        {
            q.push(root);
        }
        
        int depth = 0;
        while(!q.empty())
        {
            int size = q.size();
            depth++;//记录深度
            for(int i = 0; i < size; ++i)
            {
                Node* node = q.front();//取节点
                q.pop();

                for(int i = 0; i < node->children.size(); ++i)
                {
                    if(node->children[i] != nullptr)
                    {
                        q.push(node->children[i]);
                    }
                }
            }
        }

        return depth;
    }
};