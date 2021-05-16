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
    void createStr(TreeNode* root, string& s){
        if(root == nullptr)
        {
            return;
        }

        s += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            return;
        }

        s += '(';
        createStr(root->left, s);
        s += ')';

        if(root->right != nullptr)
        {
            s += '(';
            createStr(root->right, s);
            s += ')';
        }
    }

    string tree2str(TreeNode* root) {
        string s;
        createStr(root, s);
        return s;
    }
};