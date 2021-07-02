#include <stdio.h>
#include <math.h>
int main()
{
	int A[] = { 1,2,0,0};
	int K = 34;
    int ASize = sizeof(A) / sizeof(A[0]);
    int i = ASize - 1;
    while (i >= 0)
    {
        K = K + A[i];
        A[i] = K % 10;
        i--;
        K = K / 10;
    }
    int temp = K;
    while (temp != 0)
    {
        temp /= 10;
         ASize++;
    }
    int* a = (int*)malloc(sizeof(int) * ASize);
    a[0] = K;
    for (int j = 1,n = 0; j < ASize + 1; j++)
    {
        a[j] = A[n];
        n++;
        printf("%d ", a[j]);
    }

    return 0;
}