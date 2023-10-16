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
  printf("학번: ");
  scanf("%d", &s.number);
  printf("이름: ");
  scanf("%s", s.name);  // 배열은 포인터의 의미를 지니며 주소를 저장하고 있기
                        // 때문에 &를 붙이지 않는다.
  printf("학점: ");
  scanf("%lf", &s.grade);  // double형은 %lf로 입력받아야 한다.
  // s.number = 20150001;
  // strcpy(s.name, "james");
  // s.grade = 4.5;
  printf("학번: %d\n", s.number);
  printf("이름: %s\n", s.name);
  printf("학점: %f\n", s.grade);
  return 0;
}