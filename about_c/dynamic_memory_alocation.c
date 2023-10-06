#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pi; // pointer intiger
  pi = (int *)malloc(sizeof(int)); // malloc 메모리 할당 
  if(pi == NULL) {
    printf("동적 메모리 할당에 실패했습니다.\n");
    exit(1);
  } 
  *pi = 100;
  printf("%d\n", *pi);
  free(pi);
  // 동적 메모리 사용 후에는 반드시 free 함수를 사용하여 메모리를 해제해야 한다.
  return 0;
}