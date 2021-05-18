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
    void traversal(TreeNode* root, string path, vector<string>& vstr)
    {
        path += to_string(root->val);

        if(root->left == nullptr && root->right == nullptr)//走到叶子节点
        {
            vstr.push_back(path);
        }

        if(root->left != nullptr)
        {
            traversal(root->left, path + "->", vstr);
        }

        if(root->right != nullptr)
        {
            traversal(root->right, path + "->", vstr);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vstr;
        string path;

        if(root == nullptr)
        {
            return vstr;
        }
        traversal(root, path, vstr);
        return vstr;
    }
};