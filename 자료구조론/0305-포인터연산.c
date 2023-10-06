#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!";
	char string2[20];
	char * ptr1;
	char * ptr2;
	ptr1 = string1;

	printf("\n string1의 주소 = %u \t ptr1의 값 = %u", string1, ptr1); 
	// 같은 값이다. 
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1); 
	// 포인터가 참조하고 있는 문자열 값이 출력된다. 
	// printf("\n string1 = %s \n ptr1 = %s", string1, *ptr1); // 이건 안됨

	printf("\n\n %s", ptr1 + 7); // come true!

	ptr2 = &string1[7]; // [7]번째 주소를 ptr2에 저장. printf로 출력하면 해당 주소의 값부터 문자열의 끝까지 출력된다.  
	printf("\n %s \n\n ", ptr2); // come true! 

	for (i = 16; i >= 0; i--) {
		putchar(*(ptr1 + i)); // putchar() : 문자를 출력하는 함수
	} // !eurt emoc sraeD
	for (i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i); // string1의 문자를 string2에 복사
	}
	printf("\n\n string1 = %s", string1);
	printf("\n string2 = %s", string2);

	// string1의 문자열을 포인터로 접근해서 변경한다. 
	*ptr1 = 'P';
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1 = %s\n", string1); // Peace come true!

	getchar();
}