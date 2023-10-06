#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

struct student {
  int number;
  char name[10];
  double grade;
};

int main(void) {
  struct student s;
  s.number = 20150001;
  strcpy(s.name, "james");
  s.grade = 4.5;
  printf("학번: %d\n", s.number);
  printf("이름: %s\n", s.name);
  printf("학점: %f\n", s.grade);
  return 0;
}

/* 구조체는 설계의 측면에서 의미가 있다. 
객체지향 프로그래밍에서의 클래스의 모체라고 볼 수 있음 */