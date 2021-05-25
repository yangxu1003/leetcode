/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* Build(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend){
        if(previ == preorder.size())
        {
            return nullptr;
        }

        //没有节点
        if(inbegin > inend)
        {
            return nullptr;
        }

        int rooti = inbegin;
        while(rooti <= inend)
        {
            if(preorder[previ] == inorder[rooti])
            {
                break;
            }
            rooti++;
        }

        TreeNode* root = new TreeNode(preorder[previ]);
        previ++;

        root->left = Build(preorder, inorder, previ, inbegin, rooti-1);
        root->right = Build(preorder, inorder, previ, rooti+1, inend);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int previ = 0;
        return Build(preorder, inorder, previ, 0, inorder.size()-1);
    }
};