#include <stdio.h>

int main() {

  int i;
  int score[3] = { 10, 20, 30 };
  char grade[3] = { 'A', 'B', 'C' }; 

  printf("*** 점수와 등급 ***\n");

  for (i = 0; i < 3; i++) {
    printf("%3d학년 : 총점= %d, 등급 = %c\n", i+1, score[i], grade[i]);
  } //%3d학년 -> 3자리로 오른쪽 정렬하여 출력

  char a[] = "Hello"; // 문자열을 활용한 초기화 
  printf("%s\n", a); // Hello

}

