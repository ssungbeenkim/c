//

#define _CRT_SECURE_NO_WARNINGS  // ? scanf_s 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>

int main() {
  int i = 0, n;  // i는 반복문을 위한 변수, n은 입력받은 정수를 저장할 변수
  int multiply[9];  // 9개의 정수를 저장할 배열

  printf("1~9의 정수를 입력하세요 : ");

  while (1) {         // 무한루프
    scanf("%d", &n);  // 정수를 입력받아 n에 저장 ***
    if (n < 1 || 10 < n)
      printf("잘못 입력하셨습니다. 1부터 9사이의 숫자를 입력해주세요 : ");
    else
      break;
  }

  printf("\n");

  for (i = 0; i < 9; i++) {
    multiply[i] = n * (i + 1);  // n * (i + 1) 을 multiply[i]에 저장
    printf(" %d * %d = %d \n", n, i + 1, multiply[i]);
    // printf(" %d * %d = %d \n", n, i + 1, n * (i + 1)); // 이렇게 해도 될듯.
  }

  return 0;
}
