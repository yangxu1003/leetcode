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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        
        if(root != nullptr)
        {
            q.push(root);
        }

        vector<vector<int>> vv;
        while(!q.empty())
        {
            int length = q.size();//存的是每一层的长度
            vector<int> v;//每一层的数组
            v.clear();//初始化

            for(int i = 0; i < length; ++i)
            {
                TreeNode* node = q.front();//取节点
                q.pop();

                v.push_back(node->val);//存入
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }

            vv.push_back(v);
        }

        reverse(vv.begin(), vv.end());
        return vv;
    }
};