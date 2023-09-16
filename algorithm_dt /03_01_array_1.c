#include <stdio.h>

int main() {

  int i;
  int score[3] = { 10, 20, 30 };
  char grade[3] = { 'A', 'B', 'C' };

  printf("*** 점수와 등급 ***\n");

  for (i = 0; i < 3; i++) {
    printf("%3d학년 : 총점= %d., 등급 = %c\n", i+1, score[i], grade[i]);
  }
}



