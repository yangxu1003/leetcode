#include <stdio.h>

#include <string.h>

void reverse(char* a, int right)

{

	char temp;

	for (int i = 0; i < right; i++, right--) {

		temp = *(a + i);

		*(a + i) = *(a + right);

		*(a + right) = temp;

	}

}

int main()

{

	char a[] = "I am a student";

	reverse(a, strlen(a) - 1);

	printf("%s", a);

	return 0;

}