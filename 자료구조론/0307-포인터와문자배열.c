#include <stdio.h>
//* 강의 참조
void main() {

	char * ptrArray[2] = { "Dreams", "come" };
	char** ptrptr;
	int i;

	ptrptr = ptrArray;

	printf("\n ptrArray = %u \t ptrptr = %u", ptrArray, ptrptr); 
	printf("\n &ptrArray[0] = %u", &ptrArray[0]); 
	// 포인터 배열과 이중포인터는 같은 값을 가짐
	// 배열의 주소는 배열의 첫번째 값의 주소와 같으므로 동일하게 ptrArray의 주소를 출력
	printf("\n ptrArray[0] = %s", ptrArray[0]); // Dreams
	printf("\n ptrArray[0] = %s", ptrArray[0]+1); // reams
	printf("\n ptrArray[0] = %s", ptrArray[1]); // Come
	// ptrArray[0]은 Dreams 문자열 배열의 주소를 가리키고 있으며 
	// 그 값은 Dreams 배열의 첫번째 값의 주소와 같다. 

	printf("\n &ptrArray = %u \t &ptrptr = %u", &ptrArray, &ptrptr);
	// 포인터와 이중포인터 자체의 주소는 물론 다르다. 
	printf("\n &ptrArray = %u \t &ptrptr = %u", &ptrArray, &ptrptr);

	printf("\n *ptrArray = %u \t *ptrptr = %u", *ptrArray, *ptrptr);
	// 같은 주소를 저장하고 있으므로 같은 값이 출력된다. 
	getchar();
}