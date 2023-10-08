// 원소의 논리적, 물리적 순서 확인

#include <stdio.h>

int main(void) {
  int i, sale[4] = {157, 209, 251, 312};

  for (i = 0; i < 4; i++) {
    printf("\n address : %u sale[%d] = %d", &sale[i], i, sale[i]);
  }  // 주소가 4씩 증가하며 메모리에 연속하여 저장된 순차 구조임을 확인할 수
     // 있다.
  getchar();
}