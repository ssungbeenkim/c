#include <stdio.h>

// & : 주소 연산자로서 변수의 주소를 알아내는 연산자
// * : 참조 연산자로서 포인터 저장된 주소에 있는 값을 엑세스하는 연산자

int main() {
  int i;
  int *ptr = &i;
  // 포인터에 변수의 주소를 저장할 때는 변수 앞에 &를 붙여야 한다.
  i = 10;
  printf("%d\n", *ptr);  // 10 -> 포인터가 가지고 있는 주소에 저장된 값.
  printf("%d\n", ptr);   // 6422284 -> 포인터 변수에 저장된 주소
  printf("%d\n", &ptr);  // 6422196 -> 포인터 변수 자체의 주소
  printf("%d\n", i);     // 10
  printf("%d\n", &i);    // 6422284 -> i의 주소

  char str[6] = "Dream";
  char *ptr2 = str;
  // 포인터에 배열의 주소를 저장할 때에는 배열의 이름만 써주면 된다.
  // 배열의 이름은 배열의 첫번째 요소의 주소를 가리키고 있기 때문에 주소를
  // 저장하는것이나 마찬가지이기 때문
  printf("%s\n", str);
  printf("%u\n", &str);
  printf("%u\n", ptr2);
  printf("%s\n", ptr2);
  printf("%u\n", &str[0]);
  // 위 세줄은 같은 값을 가리킨다.

  getchar();
}