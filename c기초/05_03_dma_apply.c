#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
  int number;
  char title[100];
};

void showBook(struct Book *p, int n) {
  int i;
  for (i = 0; i < n; i++) {
    printf("book number %d: %s\n", (p + i)->number, (p + i)->title);
  }
}

int main(void) {
  struct Book *p;
  p = (struct Book *)malloc(2 * sizeof(struct Book));
  if (p == NULL) {
    printf("메모리 할당에 실패했습니다.\n");
    exit(1);
  }

  p->number = 1;
  strcpy(p->title, "C Programming");
  (p + 1)->number = 2;
  strcpy((p + 1)->title, "Data Structure");

  showBook(p, 2);
  free(p);
}

// 구조체 포인터의 경우 -> 연산자를 사용하여 접근한다.