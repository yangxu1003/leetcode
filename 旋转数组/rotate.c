
//给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;

    //判空
    if (nums == NULL)
    {
        return 0;
    }

    //翻转数组
    int left = 0, right = numsSize - 1;
    int temp = 0;
    while (left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

    //翻转前半部分
    left = 0, right = k - 1;
    while (left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

    //翻转后半部分
    left = k, right = numsSize - 1;
    while (left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}