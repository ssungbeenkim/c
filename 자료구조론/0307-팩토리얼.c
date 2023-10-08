#include <stdio.h>

long int fact(int);

int main() {
  int n, result;
  printf("Enter a number: ");
  scanf("%d", &n);
  result = fact(n);
  printf("\n Factorial of %d is %d", n, result);
  getchar();
}

long int fact(int n) {
  if (n <= 1) {
    printf("\n fact(1) 함수 호출");
    printf("\n fact(1) 값 1 반환");
    return 1;
  } else {
    printf("\n fact(%d) 함수 호출", n);
    int value = (n * fact(n - 1));
    printf("\n fact(%d) 값 %d 반환", n, value);
    return value;
  }
}