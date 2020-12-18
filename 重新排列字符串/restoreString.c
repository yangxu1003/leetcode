char* restoreString(char* s, int* indices, int indicesSize) {

    int i;
    char* ans = malloc(sizeof(char) * indicesSize + 1);//开辟一个新数组来存放字符

    ans[indicesSize] = '\0';//最后一个置为0

    for (i = 0; i < indicesSize; i++) {
        ans[indices[i]] = s[i];//依次按下标赋值
    }

    return ans;

}