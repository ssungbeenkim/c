#include <stdio.h>

int main(void) {
  char input[1001];
  gets(input);  // gets 함수를 사용하여 문자열을 입력받는다.
  int count = 0;
  while (input[count] !=
         '\0') {  // 문자열의 끝을 나타내는 널 문자를 만날 때까지 반복
    count++;
  }
  printf("입력한 문자열의 길이는 %d입니다.\n", count);
  printf("입력한 문자열은 %s입니다.\n", input);
  return 0;
}

// gets는 엔터를 칠 때까지 문자열을 입력받는 함수
