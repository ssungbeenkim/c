#include <stdio.h>

int main()
{
  printf("%d\n",100); // 정수 100을 문자열로 변환하여 출력
  printf("1001\n"); //문자열 printf("5.50n") ; // 문자열
  printf("%d\n", 100);
  printf("%d\n", 100.0); // * 0이 출력된다. 
  printf("%g\n", 100.0); // 100 출력
  printf("%g\n", 5.5); // 실수형
  printf("%g\n",5); // 2.47033e-323 * 정수형과 실수형은 메모리 저장방식이 다르다. 
  printf("%d %g\n", 100, 5.5); // 100 5.5
return 0;
}