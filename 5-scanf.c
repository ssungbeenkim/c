#include <stdio.h> 

int main()
{
  int score ; 
  printf("점수를 입력하세요. \n ");
  scanf("%d", &score); // scanf는 입력을 받는 함수이다. &는 주소를 의미한다.
  // printf("입력한 점수는 %d입니다.\n", score); // 입력한 점수는 50입니다. 
  printf("당신의 16진수 주소는 %X 입니다.\n", &score); //당신의 16진수 주소는 6F6432D8 입니다.
  printf("당신의 16진수 주소는 %X 입니다.\n", score); //당신의 16진수 주소는 6F6432D8 입니다. 당신의 16진수 주소는 32 입니다.
  // n으로 하면 값이 출력되고, &로 하면 주소가 출력된다.
  return 0;
}

