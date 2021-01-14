

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0)
    {
        return 0;
    }
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] == val)
        {
            nums[i] = nums[numsSize - 1];//Ê×Î»»¥»»
            numsSize--;//É¾µôÄ©Î²ÔªËØ
            if (numsSize == i)//ÅÐ¶ÏÊÇ·ñÎÞ¿É»»ÔªËØ
            {
                return numsSize;
            }
        }
    }
    return numsSize;
}