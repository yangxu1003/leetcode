
//����һ�����飬�������е�Ԫ�������ƶ� k ��λ�ã����� k �ǷǸ�����

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;

    //�п�
    if (nums == NULL)
    {
        return 0;
    }

    //��ת����
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

    //��תǰ�벿��
    left = 0, right = k - 1;
    while (left <= right)
    {
        temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }

    //��ת��벿��
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