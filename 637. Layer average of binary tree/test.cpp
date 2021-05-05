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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        if(root != nullptr)
        {
            q.push(root);
        }
        vector<double> v;

        while(!q.empty())
        {
            int size = q.size();//每一层的长度
            double sum = 0;//统计每一层的和
            for(int i = 0; i < size; ++i)
            {
                TreeNode* node = q.front();//取节点
                q.pop();
                sum += node->val;
                if(node->left != nullptr)
                {
                    q.push(node->left);
                }
                if(node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
            v.push_back(sum / size);//将平均值插入数组
        }
        return v;
    }
};