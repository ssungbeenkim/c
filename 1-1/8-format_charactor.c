// 07_01
#include <stdio.h>

int main()
{ // 서식문자 %p : 포인터의 주소값을 16진수로 출력한다. 
  int a = 10;
  int b = 20;

  printf("%d %d\n", a, b); // 10 20 // 데이터 
  printf("%x %x\n", a, b);  // a 14 // 데이터를 16진수로 출력
  printf("%x %x\n", &a, &b); // 6d1bb2b8 6d1bb2b4 // 주소를 16진수로 출력
  printf("%p %p\n", &a, &b); // 0x16db4f2b8 0x16db4f2b4 // 주소를 16진수로 출력 (앞에00붙음)
  // -> 주소는 실행 될 때마다 바뀐다. 
  
  return 0;

}