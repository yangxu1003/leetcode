int TreeDepth(struct TreeNode* root){
  if(root == NULL){
    return 0;            
  }

  int leftHigh = TreeDepth(root->left) + 1;
  int rightHigh = TreeDepth(root->right) + 1;

  return leftHigh > rightHigh ? leftHigh : rightHigh;
}

// 从右到左 root - right - left 次序遍历
void travel(struct TreeNode* root, int high, int* retArr, int* returnSize){
  if(root == NULL){
    return;            
  }

  if(high + 1 > *returnSize){
    *returnSize = high + 1;
    retArr[high] = root->val;                    
  }

  travel(root->right, high+1, retArr, returnSize);
  travel(root->left, high+1, retArr, returnSize);
}

int* rightSideView(struct TreeNode* root, int* returnSize){
  int high = TreeDepth(root);//求树的深度
  int* retArr = (int*)malloc(sizeof(int)*high);

  *returnSize = 0;
  travel(root, 0, retArr, returnSize);
  return retArr;
}
