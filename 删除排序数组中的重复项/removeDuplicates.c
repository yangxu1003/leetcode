int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2)
    {
        return numsSize;
    }
    int j = 0;//jΪ�������ֵ��±�
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            j++;
            nums[j] = nums[i + 1];//�����һ�γ��ֲ�ͬ������
        }
    }
    return j + 1;
}