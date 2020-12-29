bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char des1[1000];
    char des2[1000];

    memset(des1, 0, 1000);
    memset(des2, 0, 1000);

    int i;
    for (i = 0; i < word1Size; i++)
    {
        strcat(des1, word1[i]);
    }
    for (i = 0; i < word2Size; i++)
    {
        strcat(des2, word2[i]);
    }

    if (strcmp(des1, des2) == 0)
    {
        return true;
    }
    return false;
}