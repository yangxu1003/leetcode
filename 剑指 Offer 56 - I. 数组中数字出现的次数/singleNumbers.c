/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    int single = 0;
    int k = 0;
    for (int i = 0; i < numsSize; i++)
    {
        single ^= nums[i];
    }
    while ((single & 1) == 0)
    {
        single >>= 1;
        k++;
    }
    *returnSize = 2;
    int* a = (int*)malloc((sizeof(int)) * 2);
    a[0] = 0;
    a[1] = 0;
    for (int j = 0; j < numsSize; j++)
    {
        if ((nums[j] >> k) & 1) {
            a[0] ^= nums[j];
        }
        else
        {
            a[1] ^= nums[j];
        }
    }

    return a;
}