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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr)
        {
            q.push(root);
        }

        vector<int> v;
        while(!q.empty())
        {
            int size = q.size();//存每一层的长度
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();
                q.pop();
                if(i == size - 1)
                {
                    v.push_back(node->val);//将每层的末尾元素存入数组v
                }
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }

        return v;
    }
};