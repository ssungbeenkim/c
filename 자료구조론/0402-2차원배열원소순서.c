// 2차원 배열의 논리적, 물리적 순서 확인
#include <stdio.h>

int main(void) {
  int i, n = 0, *ptr;
  int sale[2][4] = {{157, 209, 251, 312}, {168, 229, 310, 412}};

  ptr = &sale[0][0];  // sale[0][0]의 주소를 ptr에 값으로 저장
  for (i = 0; i < 8; i++) {
    printf("\n address : %u sale %d = %d", ptr, i, *ptr);
    ptr++;  // ptr에 저장된 주소값을 4씩 증가시킴
  }
  getchar();
}
// c 컴파일러가 행 우선으로 2차원 배열을 저장하는 것을 확인할 수 있다.