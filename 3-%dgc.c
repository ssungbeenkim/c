/* 
연산 가능 구역
서식문자에 대해 알아본다. 
아스키가 7비트인 이유는 데이터를 보낼 때 받는 쪽에서 맞게 온건지 확인할 때 쓰는 패리티 비트가 있어서 그렇다. 
*/

#include <stdio.h>

int main()
{
  printf("%d + %d = %d\n", 10, 20, 30);
  printf("%d + %d = %d\n", 10, 20, 10+20); // 계산 가능 영역
  printf("%d,%c,%g\n",10,65,10.0); // 10,A,10 정수 10, ASCII65(A, 실수10
  printf("%C\n",65); // %c와 동알한 결과 A가 출력된다. 

  
  int k; // 메모리 확보 
  k = 50; //메모리에 값을 넣음
  int n = 50; //메모리 확보하고 값을 넣음
  /* 변수 영역에 식별자가 저장되고 데이터 영역에 메모리를 확보한다. */
  char m = 'A';

  printf("%d\n", k); //50
  printf("%d\n", sizeof(n)); //4  byte가 출력된다. 
  printf("%c\n", m); // A
  printf("%d\n", sizeof(m)); //1

  /* 데이터 바꾸기  */
  int a = 10;
  int b = 20;
  printf("%d %d\n", a,b);

// 매개변수가 필요하다. 
  int t = a;
  printf("%d %d %d\n", a,b,t);
  a = b;
  printf("%d %d %d\n", a,b,t);
  b = t;
  printf("%d %d %d\n", a,b,t);
  
  printf("%d %c \n", 65, 65) ;
  printf("%d %c \n", 'a', 'a');
  


  return 0;
}