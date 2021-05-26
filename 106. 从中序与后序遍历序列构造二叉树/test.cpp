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
    TreeNode* Build(vector<int>& inorder, vector<int>& postorder, int& posti, int inbegin, int inend)
    {
        if(posti < 0)
        {
            return nullptr;
        }

        if(inbegin > inend)
        {
            return nullptr;
        }

        //根据根节点划分中序左右区间
        int rooti = inend;
        while(rooti >= inbegin)
        {
            if(postorder[posti] == inorder[rooti])
            {
                break;
            }
            rooti--;
        }

        TreeNode* root = new TreeNode(postorder[posti]);
        posti--;

        //先右后左
        //[rooti+1,inend]rooti[inbegin, rooti-1]
        root->right = Build(inorder, postorder, posti, rooti+1, inend);
        root->left = Build(inorder, postorder, posti, inbegin, rooti-1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int posti = postorder.size()-1;
        return Build(inorder, postorder, posti, 0, inorder.size()-1);
    }
};