char* restoreString(char* s, int* indices, int indicesSize) {

    int i;
    char* ans = malloc(sizeof(char) * indicesSize + 1);//����һ��������������ַ�

    ans[indicesSize] = '\0';//���һ����Ϊ0

    for (i = 0; i < indicesSize; i++) {
        ans[indices[i]] = s[i];//���ΰ��±긳ֵ
    }

    return ans;

}