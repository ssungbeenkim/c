# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int main() {
  
  int user = 0;
  int robot = 0;

  srand(time(0));
  int number = rand();

  if(number%2 == 0) {
    robot = 2;
  } else {
    robot = 1;
  }

  printf("홀수면 1, 짝수면 2를 입력하세요: ");
  scanf("%d", &user);

  if(user == robot) {
    printf("당신이 이겼습니다.\n");
  } else {
    printf("당신이 졌습니다.\n");
  }

  return 0;
}