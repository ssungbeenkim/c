/* 
연산 가능 구역
서식문자에 대해 알아본다. 
아스키가 7비트인 이유는 데이터를 보낼 때 받는 쪽에서 맞게 온건지 확인할 때 쓰는 패리티 비트가 있어서 그렇다. 
*/

#include <stdio.h>

int main()
{
  int a = 1850;
  // sizeof(a)
  printf("%d\n", sizeof(a)); // 4
  printf("%d", sizeof(a)); // 4


  return 0;
}