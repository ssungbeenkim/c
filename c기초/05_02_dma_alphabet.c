#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char *pc = NULL;
  int i;
  pc = (char *)malloc(100 * sizeof(char));
  if (pc == NULL) {
    printf("동적 메모리 할당에 실패했습니다.\n");
    exit(1);
  }
  // pc가 가리키는 포인터를 1씩 증가시키며 알파벳 소문자를 삽입
  for (i = 0; i < 26; i++) {
    *(pc + i) = 'A' + i;
    // 이렇게 할 수 있는것은, pc가 가리키는 포인터가 char type이므로 주소연산시
    // 1씩 증가하기 때문
  }
  *(pc + i) = 0;  // 아스키 코드에서 0은 NULL을 의미

  free(pc);  // 동적 메모리 할당 해제
  return 0;
}

// 100개의 문자가 들어갈 수 있는 동적 메모리를 할당
