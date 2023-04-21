// 07_01
#include <stdio.h>

int main()
{ 
  printf("%d\n", 5<<0); // 5  -> 5*2^0
  printf("%d\n", 5<<1); // 10 -> 5*2^1
  printf("%d\n", 5<<2); // 20 -> 5*2^2 
  printf("%d\n", 5<<3); // 40 -> 5*2^3
  printf("%d\n", 5<<4); // 80 -> 5*2^4
  printf("%d\n", 5<<5); // 160 -> 5*2^5
  printf("%d\n", 5<<6); // 320 -> 5*2^6

  //  관계연산자 
  int a = 0 ;
  int b = 0 ;
  if(a==b) //1/ 0=20 6 = 20 거짓 = 0 참은
  printf("같다.\n") ;
  else
  printf("다르다.\n") ;


  return 0;

}