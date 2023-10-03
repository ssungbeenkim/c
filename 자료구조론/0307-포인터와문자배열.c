#include <stdio.h>

void main() {
	int i;
	char* ptrArray[4] = { { "Korea" },{ "Seoul" },{ "Seongdong" },{ "222" } };
	for (i = 0; i < 4; i++)
		printf("\n %s", ptrArray[i]);

	ptrArray[2] = "Wangsimri";
	printf("\n\n");
	for (i = 0; i < 4; i++)
		printf("\n %s", ptrArray[i]);

	getchar();
}