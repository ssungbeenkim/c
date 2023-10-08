#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pi, i;
  pi = (int *)malloc(100 * sizeof(int));
  if (pi == NULL) {
    printf("동적 메모리 할당에 실패했습니다. \n");
    exit(1);
  }
  for (i = 0; i < 5; i++) {
    pi[i] = (i + 1) * 100;
  }
  for (i = 0; i < 5; i++) {
    printf("%d\n", *(pi + i));  // 100 200 300 400 500
    // 이렇게 주소연산을 통해 접근하는 원리는 pi가 int형 포인터이므로 4씩
    // 증가하는 원리에 의한 것이다.
    printf("%d\n", pi[i]);  // 100 200 300 400
    // 500
  }
  free(pi);
}
