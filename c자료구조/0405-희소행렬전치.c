// 희소행렬의 전치 연산
#include <stdio.h>

typedef struct {
  int row;
  int col;
  int value;
} term;
// typedef: 구조체를 정의할 때 struct 키워드를 생략할 수 있게 해준다.

void smTranspose(term a[], term b[]) {
  int r, c, v, i, j, p;
  r = a[0].row;    // 희소 행렬 a의 행 개수
  c = a[0].col;    // 희소 행렬 a의 열 개수
  v = a[0].value;  // 희소 행렬 a에서 0이 아닌 원소의 개수
  b[0].row = c;    // 전치 행렬 b의 행 개수
  b[0].col = r;    // 전치 행렬 b의 열 개수
  b[0].value = v;  // 전치 행렬 b의 원소 개수
  if (v > 0) {     // 0이 아닌 원소가 하나도 없다면 전치가 불가
    // p를 1부터 증가시키면서 희소행렬 a의 원소를 돌며 열 번호 0인 것부터 차례로
    // 전치 행렬 b에 삽입
    p = 1;
    for (i = 0; i < c; i++)  // 전치 행렬 b의 행 = 희소행열 a의 열
      for (j = 1; j <= v; j++)  // 희소 행렬 a의 원소 인덱스
        if (a[j].col == i) {  // a의 열 번호가 0인 것부터 차례로 b에 삽입
          b[p].row = a[j].col;
          b[p].col = a[j].row;
          b[p].value = a[j].value;
          p++;
        }
  }
}

int main(void) {
  term a[] = {{8, 7, 10}, {0, 2, 2},  {0, 6, 12}, {1, 4, 7},
              {2, 0, 23}, {3, 3, 31}, {4, 1, 14}, {4, 5, 25},
              {5, 6, 6},  {6, 0, 52}, {7, 4, 11}};
  term b[sizeof(a) / sizeof(a[0])];  // 배열 원소 개수 계산해서 b[]의 크기 정의
  int i;

  printf("<<희소 행렬 a>>");
  for (i = 0; i <= a[0].value; i++)
    printf("\n[%3d, %3d, %3d ] ", a[i].row, a[i].col, a[i].value);

  smTranspose(a, b);

  printf("\n\n<<희소 행렬 b>>");
  for (i = 0; i <= b[0].value; i++)
    printf("\n[%3d, %3d, %3d ] ", b[i].row, b[i].col, b[i].value);

  getchar();
  return 0;
}