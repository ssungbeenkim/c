#include <stdio.h>
int main(){
  int money = 0;
  printf("돈을 입력하세요: \n");
  scanf("%d", &money);
  printf("입력한 돈은 %d원 입니다.\n", money);

  int m_50000 = money/50000;
  money = money%50000;
  printf("50000원권: %d장\n", m_50000);

  int m_10000 = money/10000;
  money = money%10000;
  printf("10000원권: %d장\n", m_10000);

  int m_5000 = money/5000;
  money = money%5000;
  printf("5000원권: %d장\n", m_5000);

  int m_1000 = money/1000;
  money = money%1000;
  printf("1000원권: %d장\n", m_1000);

  printf("잔돈: %d원\n", money);
}