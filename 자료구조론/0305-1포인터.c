#include <stdio.h>

// & : 주소 연산자로서 변수의 주소를 알아내는 연산자
// * : 참조 연산자로서 포인터 저장된 주소에 있는 값을 엑세스하는 연산자 

int main() {
  int i;
  int *ptr = &i;
  i = 10;
  printf("%d\n", *ptr); // 10
  printf("%d\n", ptr); // 6422284
  printf("%d\n", i); // 10
  printf("%d\n", &i); // 6422284
  return 0;
  }