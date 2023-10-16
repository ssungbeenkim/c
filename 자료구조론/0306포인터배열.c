
#include <stdio.h>

void main() {
  int i;
  char* ptrArray[4] = {{"Dreams"}, {"come"}, {"true!"}, {"!"}};
  for (i = 0; i < 4; i++) {
    printf("%s\n", ptrArray[i]);
    printf("%u\n", &ptrArray[i]);  // 8씩 증가: 포인터가 저장하는 주소의 크기
  }

  ptrArray[0] = "Peace";

  for (i = 0; i < 4; i++) {
    printf("%s\n", ptrArray[i]);
  }

  getchar();
}

/*
배열은 그 자체로 포인터의 의미를 가진다.
배열의 이름은 배열의 첫번째 요소의 주소를 가리키고 있기 때문에 주소를
저장하는것이나 마찬가지이기 때문

포인터 배열
여러개의 포인터를 하나의 배열로 구성.
배열의 특징과 포인터의 특징을 모두 활용할 수 있다.
 */
