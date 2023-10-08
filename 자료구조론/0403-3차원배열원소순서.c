// 3차원 배열의 논리적, 물리적 순서 확인하기
#include <stdio.h>

int main(void) {
  int i, n = 0, *ptr;
  int sale[2][2][4] = {{{157, 209, 251, 312}, {168, 229, 310, 412}},
                       {{157, 209, 251, 312}, {168, 229, 310, 412}}};

  ptr = &sale[0][0][0];  // sale[0][0][0]의 주소를 ptr에 값으로 저장
  for (i = 0; i < 16; i++) {
    printf("\n address : %u sale %2d = %3d", ptr, i, *ptr);
    ptr++;
  }

  getchar();
}