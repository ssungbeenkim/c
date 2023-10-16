#include <stdio.h>

// 두 변수의 값을 서로 바꾸는 포인터 함수
void swap(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
/* 포인터를 사용하지 않으면 함수 내에서만 매개변수가 사용되기 때문에 값이 바뀌지
 * 않는다. */

int main(void) {
  int x = 1;
  int y = 2;
  swap(&x, &y);
  printf("x = %d\ny = %d\n", x, y);
  return 0;
}

// 포인터를 활용하면 언제 어디에서든 값을 바꾸는 것이 가능하다.
// <string.h>에 있는 strlen() 함수를 사용해 길이를 구할수도 있다.
// 동일 라이브러리에 들어있는 strcmp() 함수는 두 문자의 사전순 순서를 판별할 수
// 있는 기능을 제공한다. strcpy() 함수는 문자열을 복사하는 기능을 제공한다.

/*
 * pointer https://blog.naver.com/sharonichoya/220483089874
 */