
//给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int len = m + n - 1;
    int n1 = m - 1;//n1为nums1的最后一个元素的下标
    int n2 = n - 1;//n2为nums2的最后一个元素的下标
    while (n1 >= 0 && n2 >= 0)
    {
        //有序数组，从后往前比
        if (nums2[n2] > nums1[n1])
        {
            nums1[len] = nums2[n2];
            n2--;
            len--;
        }
        else
        {
            nums1[len] = nums1[n1];
            n1--;
            len--;
        }
    }

    //当第二个数组的元素大于0就存入，不用管第一个数组它本身已经存进去了
    while (n2 >= 0)
    {
        nums1[len] = nums2[n2];
        n2--;
        len--;
    }

}