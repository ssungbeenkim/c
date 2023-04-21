#include <stdio.h>

int main()
{ // 변수 바꾸기 
  int a = 10 , b = 5, temp = 0;
  printf("a=%d b=%d temp=%d\n", a, b,temp); // a=10 b=5
  temp = a;
  printf("a=%d b=%d temp=%d\n", a, b, temp); // a=10 b=5 temp=10
  a=b;
  printf("a=%d b=%d temp=%d\n", a, b, temp); // a=5 b=5 temp=10 
  b=temp;
  printf("a=%d b=%d temp=%d\n", a, b, temp); // a=5 b=10 temp=10 
  
  // 후위, 선위 연산자 
  int x = 10, r = 0;
  r = x++;
  printf("x=%d r=%d\n", x, r); // a=11 r=10
  x = 10, r = 0;
  r = ++x;
  printf("x=%d r=%d\n", x, r); // a=11 r=11
  
  return 0;

}