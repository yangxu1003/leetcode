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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        if(root != nullptr)
        {
            q.push(root);
        }
        
        vector<vector<int>> vv;
        
        while(!q.empty())
        {
            int size = q.size();//每一组的长度
            vector<int> v;

            for(int i = 0; i < size; ++i)
            {
                Node* node = q.front();
                q.pop();
                v.push_back(node->val);

                for(int i = 0; i < node->children.size(); ++i)//将节点的孩子入队
                {
                    if(node->children[i] != nullptr)//每组子节点都由null值分隔
                    {
                        q.push(node->children[i]);
                    }
                }
            }

            vv.push_back(v);
        }

        return vv;
    }
};