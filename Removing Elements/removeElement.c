

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0)
    {
        return 0;
    }
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] == val)
        {
            nums[i] = nums[numsSize - 1];//��λ����
            numsSize--;//ɾ��ĩβԪ��
            if (numsSize == i)//�ж��Ƿ��޿ɻ�Ԫ��
            {
                return numsSize;
            }
        }
    }
    return numsSize;
}