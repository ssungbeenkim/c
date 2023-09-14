#include <stdio.h>

int main()
{
  
  
  int munja1 = '0';
  int munja2 = 0;
  printf("%c\n", munja1);  // 0
  printf("%d\n", munja1); // 48 문자 0의 아스키 코드값
  printf("%c\n", munja2);  // ASCII 0은 NULL이라서 아무것도 출력되지 않는다. 
  printf("%c\n", 64);  // @
  printf("%d\n", munja2); // 0

  int chr = 'a';
  printf("%d %c\n", chr, chr); // 97 a 
  printf("%d %c\n", chr+5, chr+5); // 102 f

  char num = 97;
  printf("%c\n", num); // a
  printf("%d\n", '1'); // 49
  printf("%c\n", 146); // �
  printf("%d\n", 97+49); // 146
  printf("%c %c %c\n", num+'1', '\t', num+49); // �        �
  printf("%d %d %d\n", num+'1', '\t', num+49); // 146 9 146
  printf("%c\n", 98); // 


}