/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

bool _isSymmetric(TreeNode* left,TreeNode* right)
{
    //左孩子和右孩子都为空，说明遍历结束都没找到不相等的
    if(left == nullptr && right == nullptr)
    {
        return true;
    }

    //如果其中一个为空,返回false
    if(left == nullptr || right == nullptr)
    {
        return false;
    }

    if(left->val != right->val)
    {
        return false;
    }

    return _isSymmetric(left->left,right->right) && _isSymmetric(left->right,right->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }

        return _isSymmetric(root->left,root->right);
    }
};