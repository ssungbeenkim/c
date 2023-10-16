// 다항식의 선형 리스트 표현과 덧셈 연산
#include <stdio.h>
#define MAX(a, b) ((a > b) ? a : b)
#define MAX_DEGREE 50

typedef struct {
  int degree;
  float coef[MAX_DEGREE];

} polynomial;

polynomial addPoly(polynomial A, polynomial B) {
  polynomial C;

  int A_index = 0, B_index = 0, C_index = 0;
  int A_degree = A.degree, B_degree = B.degree;
  C.degree = MAX(A.degree, B.degree);

  while (A_index <= A.degree && B_index <= B.degree) {
    if (A_degree > B_degree) {  // A의 차수가 더 높은 경우
      C.coef[C_index++] = A.coef[A_index++];
      A_degree--;
    } else if (A_degree == B_degree) {  // A, B의 차수가 같은 경우
      C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
      A_degree--;
      B_degree--;
    } else {  // B의 차수가 더 높은 경우
      C.coef[C_index++] = B.coef[B_index++];
      B_degree--;
    }
  }
  return C;
}

void printPoly(polynomial P) {
  int i, degree;
  degree = P.degree;

  for (i = 0; i <= P.degree; i++) {
    printf("%3.0fx^%d", P.coef[i], degree--);
    if (i < P.degree) printf(" +");
  }
  printf("\n");
}

int main(void) {
  polynomial A = {3, {4, 3, 5, 0}};
  polynomial B = {4, {3, 1, 0, 2, 1}};
  polynomial C;

  C = addPoly(A, B);

  printf("\n A(x) =");
  printPoly(A);
  printf("\n B(x) =");
  printPoly(B);
  printf("\n C(x) =");
  printPoly(C);

  getchar();
  return 0;
}