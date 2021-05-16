/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool searchPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path){
        if(root == nullptr)
        {
            return false;
        }

        path.push(root);
        if(root == x)
        {
            return true;
        }
        
        if(searchPath(root->left, x, path))
        {
            return true;
        }
        
        if(searchPath(root->right, x, path))
        {
            return true;
        }
        
        path.pop();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;

        searchPath(root, p, pPath);//找到节点路径
        searchPath(root, q, qPath);

        while(pPath.size() > qPath.size())//长度相等时在比较
        {
            pPath.pop();
        }

        while(qPath.size() > pPath.size())
        {
            qPath.pop();
        }

        while(qPath.top() != pPath.top())
        {
            qPath.pop();
            pPath.pop();
        }


        return qPath.top();
    }
};