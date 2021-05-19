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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* parent  = nullptr;
        TreeNode* cur = root;//待删除节点
        while(cur)
        {
            if(cur->val > key)
            {
                parent = cur;
                cur = cur->left;
            }
            else if(cur->val < key)
            {
                parent = cur;
                cur = cur->right;
            }
            else
            {
                //找到删除位置
                if(cur->left == nullptr)//左孩子为空
                {
                    if(cur == root)
                    {
                        root = cur->right;//更新root
                    }
                    else
                    {
                        if(cur == parent->left)
                        {
                            parent->left = cur->right;
                        }
                        else
                        {
                            parent->right = cur->right;
                        }
                        delete cur;
                    }
                    cur = nullptr;
                }
                else if(cur->right == nullptr)//右为空
                {
                    if(root == cur)
                    {
                        root = cur->left;
                    }
                    else
                    {
                        if(cur == parent->left)
                        {
                            parent->left = cur->left;
                        }
                        else
                        {
                            parent->right = cur->left;
                        }
                        delete cur;
                    }
                    cur = nullptr;
                }
                else//左右都不为空
                {
                    TreeNode* subParent = cur;
                    TreeNode* subMin = cur->right;//找右孩子的最小值
                    while(subMin->left)
                    {
                        subParent = subMin;
                        subMin = subMin->left;
                    }

                    cur->val = subMin->val;//赋值替换

                    if(cur== subParent)
                    {
                        subParent->right = subMin->right;
                    }
                    else
                    {
                        subParent->left = subMin->right;
                    }
                    delete subMin;
                }
                return root;
            }
            
        }
        return root;
    }
};