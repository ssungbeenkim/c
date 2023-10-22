#include <stdio.h>

typedef enum { false, true } boolean;
boolean lock = true;
int balance = 0;

int main() {
  while (lock == true) {
    lock = true;
    balance = balance + 10;  // 입금과정 -> 임계구역
    lock = false;
  }
  printf("Balance: %d\n", balance);
  return 0;
}
