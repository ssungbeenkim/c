#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], * ptr1, * ptr2;

	ptr1 = string1;
	printf("\n string1의 주소 = %u \t ptr1 = %u", string1, ptr1);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7); // come true!
	ptr2 = &string1[7]; // 
	printf("\n %s \n\n ", ptr2); // come true! 

	for (i = 16; i >= 0; i--) {
		putchar(*(ptr1 + i)); // putchar() : 문자를 출력하는 함수
	} // !eurt emoc sraeD
	for (i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i); // string1의 문자를 string2에 복사
	}
	printf("\n\n string1 = %s", string1);
	printf("\n string2 = %s", string2);

	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1); // Peace come true!

	getchar();
}