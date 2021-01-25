int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2)
    {
        return numsSize;
    }
    int j = 0;//j为存入数字的下标
    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != nums[i + 1])
        {
            j++;
            nums[j] = nums[i + 1];//存入第一次出现不同的数字
        }
    }
    return j + 1;
}