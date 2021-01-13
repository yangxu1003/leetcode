/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void AdjustDown(int* retArr, int k, int root)
{
    int parent = root;
    int child = parent * 2 + 1;
    while (child < k)
    {
        if (child + 1 < k && retArr[child + 1] > retArr[child])
        {
            ++child;
        }
        if (retArr[parent] < retArr[child])
        {
            int tmp = retArr[parent];
            retArr[parent] = retArr[child];
            retArr[child] = tmp;

            //迭代
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            break;
        }
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize) {
    *returnSize = k;
    if (k == 0)
    {
        return NULL;
    }

    //建立k个数的大堆
    int* retArr = (int*)malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++)
    {
        retArr[i] = arr[i];
    }
    for (int i = (k - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown(retArr, k, i);
    }

    //其余元素和堆顶比较，小的替换
    for (int i = k; i < arrSize; ++i)
    {
        if (arr[i] < retArr[0])
        {
            retArr[0] = arr[i];
            AdjustDown(retArr, k, 0);
        }
    }

    return retArr;
}