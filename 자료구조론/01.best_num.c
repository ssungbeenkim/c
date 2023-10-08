/* 입력을 받아 간단한 조건문으로 최대값을 출력하는 코드 */

#include <stdio.h>

int main(void) {
  int a, b, c;

  printf("세 정수중 최대값을 구합니다.\n");
  printf("a의 값: ");
  scanf("%d", &a);  // scanf: 키보드로 입력받는 함수
  printf("b의 값: ");
  scanf("%d", &b);
  printf("c의 값: ");
  scanf("%d", &c);

  int max = a;
  if (b > max) max = b;
  if (c > max) max = c;

  printf("최대값은 %d입니다.\n", max);

  return 0;
}