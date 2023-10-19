#include <stdio.h>
#include <stdlib.h>

// 다항식 리스트의 노드 구조를 구조체로 정의
float coef;
typedef struct ListNode {
  float coef;
  int expo;
  struct ListNode* link;
} ListNode;

// 다항식 리스트의 head 노드를 구조체로 정의
typedef struct ListHead {
  ListNode* head;
} ListHead;

// 공백 다항식 리스트를 생성하는 연산
ListHead* createLinkedList(void) {
  ListHead* L;
  L = (ListHead*)malloc(sizeof(ListHead));
  L->head = NULL;
  return L;
}

// 다항식 리스트에 마지막 노드를 추가하는 연산
void appendTerm(ListHead* L, float coef, int expo) {
  ListNode* newNode;
  ListNode* p;
  newNode = (ListNode*)malloc(sizeof(ListNode));
  newNode->coef = coef;
  newNode->expo = expo;
  newNode->link = NULL;

  if (L->head == NULL) {  // 다항식 리스트가 공백인 경우
    L->head = newNode;
    return;
  } else {  // 다항식 리스트가 공백이 아닌 경우
    p = L->head;
    while (p->link != NULL) {
      p = p->link;  // 리스트의 마지막 노드를 찾음
    }
    p->link = newNode;  // 새 노드 연결
  }
}

// 두 다항식의 덧셈을 구하는 연산
void addPoly(ListHead* A, ListHead* B, ListHead* C) {
  ListNode* pA = A->head;
  ListNode* pB = B->head;
  float sum;

  // 두 다항식에 노드가 있는 동안 반복 수행
  while (pA && pB) {
    // 다항식 A의 지수가 다항식 B의 지수와 같은 경우
    if (pA->expo == pB->expo) {
      sum = pA->coef + pB->coef;
      appendTerm(C, sum, pA->expo);
      pA = pA->link;
      pB = pB->link;
    }
    // 다항식 A의 지수가 다항식 B의 지수보다 큰 경우
    else if (pA->expo > pB->expo) {
      appendTerm(C, pA->coef, pA->expo);
      pA = pA->link;
    }
    // 다항식 A의 지수가 다항식 B의 지수보다 작은 경우
    else {
      appendTerm(C, pB->coef, pB->expo);
      pB = pB->link;
    }
  }
  // 다항식 A에 남아 있는 노드 복사
  for (; pA != NULL; pA = pA->link) appendTerm(C, pA->coef, pA->expo);

  // 다항식 B에 남아 있는 노드 복사
  for (; pB != NULL; pB = pB->link) appendTerm(C, pB->coef, pB->expo);
}

// 다항식 리스트를 출력하는 연산
void printPoly(ListHead* L) {
  ListNode* p = L->head;
  for (; p; p = p->link) {
    printf("%3.0fx^%d", p->coef, p->expo);
    if (p->link != NULL) printf(" +");
  }
}

int main(void) {
  ListHead *A, *B, *C;

  // 공백 다항식 리스트 A, B, C 생성
  A = createLinkedList();
  B = createLinkedList();
  C = createLinkedList();

  appendTerm(A, 4, 3);  // 다항식 리스트 A에 4x3 노드 추가
  appendTerm(A, 3, 2);  // 다항식 리스트 A에 3x2 노드 추가
  appendTerm(A, 5, 1);  // 다항식 리스트 A에 5x1 노드 추가
  printf("\n A(x) =");
  printPoly(A);  // 다항식 리스트 A 출력

  appendTerm(B, 3, 4);  // 다항식 리스트 B에 3x4 노드 추가
  appendTerm(B, 1, 3);  // 다항식 리스트 B에 1x3 노드 추가
  appendTerm(B, 2, 1);  // 다항식 리스트 B에 2x1 노드 추가
  appendTerm(B, 1, 0);  // 다항식 리스트 B에 1x0 노드 추가
  printf("\n B(x) =");
  printPoly(B);  // 다항식 리스트 B 출력

  addPoly(A, B, C);  // 다항식의 덧셈 연산 수행
  printf("\n C(x) =");
  printPoly(C);  // 다항식 리스트 C 출력

  getchar();
  return 0;
}