
//�������������������� nums1 �� nums2�����㽫 nums2 �ϲ��� nums1 �У�ʹ nums1 ��Ϊһ���������顣

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int len = m + n - 1;
    int n1 = m - 1;//n1Ϊnums1�����һ��Ԫ�ص��±�
    int n2 = n - 1;//n2Ϊnums2�����һ��Ԫ�ص��±�
    while (n1 >= 0 && n2 >= 0)
    {
        //�������飬�Ӻ���ǰ��
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

    //���ڶ��������Ԫ�ش���0�ʹ��룬���ùܵ�һ�������������Ѿ����ȥ��
    while (n2 >= 0)
    {
        nums1[len] = nums2[n2];
        n2--;
        len--;
    }

}