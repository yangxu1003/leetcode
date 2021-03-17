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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return isBalanced(root, depth);
    }

    bool isBalanced(TreeNode* root, int& pDepth) {
        if(root == NULL){
            pDepth = 0;
            return true;
        }

        //如果左子树已经不平衡，直接返回false
        int leftDepth = 0;
        if(isBalanced(root->left, leftDepth) == false){
            return false;
        }  

        //如果右子树已经不平衡，直接返回false
        int rightDepth = 0;    
        if(isBalanced(root->right, rightDepth) == false) {
             return false;
        } 
           
        //左右子树都是平衡树，比较左右子树高度差是否大于1    
        if(abs(leftDepth-rightDepth) > 1)
        {
            return false;
        }

        pDepth = leftDepth > rightDepth ? leftDepth+1 : rightDepth+1;
        return true;
    }
};
