// 06-02
#include <stdio.h>
int main() 
{
  int a=10, b=3;
  double c = a/b; 
  double d = 10.0;
  double e = 3.0;

  double f = d/e;
  printf("%d\n", a+b); // 13
  printf("%d\n", a-b); // 7
  printf("%d\n", a*b); // 30
  printf("%d\n", a/b); // 3 * int/int는 int이다.
  printf("%d\n", a%b); // 1

  printf("%5.2f\n", c); // 3.00 * a,b가 int이기 때문에 c는 3.00이다.
  //5자리, 소숫점 이하 2자리이하 반올림

  printf("%5.2f\n", d/e); // 3.33
  printf("%5.2f\n", f); // 3333333.33
  printf("%20.2f\n", f); //          3333333.33 -> 앞에 10자리 공백이 생긴다.(총 20자리 중 점 포함10자리를 썼고 소숫점 2자리 이후 반올림이다.)

  printf("d=%10.2f e=%10.2f f=%10.10f\n", d, e, f); 
  // d=     10.00 e=      3.00 f=3.3333333333
  return 0;
}

// %g, %f? 