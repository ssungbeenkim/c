#include <stdio.h>

// 구조체형 선언 후 구조체 변수 선언
struct employee {
  char name[20]; 
  char id[20];
  int pay;
  };

  int main() {
  int i;
  struct employee Lee[2] = { // 구조체형 변수 선언과 동시에 초기화
    {"이순신", "2012001", 3000000},
    {"강감찬", "2013001", 3500000}
  };

  for(i = 0; i < 2; i++) {
    printf("%s %s %d\n", Lee[i].name, Lee[i].id, Lee[i].pay);  
  } 

  getchar();
};