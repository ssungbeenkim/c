#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
  char data[4];
  struct ListNode* link;
} listNode;

// 리스트의 시작을 나타애는 head 노드를 구조체로 정의
typedef struct {
  listNode* head;
} linkedList_h;

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void) {
  linkedList_h* L;
  L = (linkedList_h*)malloc(sizeof(linkedList_h));
  L->head = NULL;  // 공백 리스트이므로 NULL로 설정
  return L;
}

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h* L) {
  listNode* p;
  while (L->head != NULL) {
    p = L->head;              // head가 가리키는 노드를 p에 할당
    L->head = L->head->link;  // head를 다음 노드로 변경
    free(p);                  // 첫번째 노드의 동적 메모리 해제
    p = NULL;                 //?
  }
}

// 연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h* L) {
  listNode* p;
  printf("L = (");
  p = L->head;
  while (p != NULL) {
    printf("%s", p->data);
    p = p->link;
    if (p != NULL) printf(", ");
  }
  printf(") \n");
}

// 첫 번째 노드로 삽입하는 연산
void insertFirstNode(linkedList_h* L, char* x) {
  listNode* newNode;
  newNode = (listNode*)malloc(sizeof(listNode));  // 삽입할 새 노드 할당
  strcpy(newNode->data, x);  // 새 노드에 데이터 필드에 x 저장
  newNode->link = L->head;
  L->head = newNode;
}

// pre 뒤에 노드를 삽입하는 연산
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
  listNode* newNode;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  if (L->head == NULL) {  // 공백 리스트인 경우 만든 노드를 넣어줌
    newNode->link = NULL;
    L->head = newNode;
  } else if (pre == NULL) {  // pre가 NULL인 경우 첫 번째 노드로 삽입
    newNode->link = L->head;
    L->head = newNode;
  } else {
    newNode->link = pre->link;  // 새 노드를 pre의 다음 노드로 연결
    pre->link = newNode;        // predml 다음 값으로 새 노드를 연결.
  }
}

// 마지막 노드로 삽입하는 연산
void insertLastNode(linkedList_h* L, char* x) {
  listNode* newNode;
  listNode* temp;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  newNode->link = NULL;
  if (L->head ==
      NULL) {  // 공백 리스트의 경우 만들어진 새 노드를 첫 번째 노드로 연결
    L->head = newNode;
    return;
  }
  temp = L->head;
  while (temp->link != NULL) temp = temp->link;
  //  temp는 결국 마지막 노드를 가리키게 됨
  temp->link = newNode;  // 마지막 노드에 새 노드를 연결
}

int main(void) {
  linkedList_h* L;
  L = createLinkedList_h();
  printf("(1) 공백 리스트 생성 \n");
  printList(L);

  printf("\n(2) 리스트에 [수] 노드 삽입 \n");
  insertFirstNode(L, "수");
  printList(L);

  printf("\n(3) 리스트 마지막에 [금] 노드 삽입하기 \n");
  insertLastNode(L, "금");
  printList(L);

  printf("\n(4) 리스트 첫 번째에 [월]노드 삽입 \n");
  insertFirstNode(L, "월");
  printList(L);

  printf("\n(5) 리스트의 두번째 값으로 [화] 노드 삽입 \n");
  insertMiddleNode(L, L->head, "화");
  printList(L);

  printf("\n(5) 리스트 공간을 해제하여 공백 리스트로 만들기 \n");
  freeLinkedList_h(L);
  printList(L);

  getchar();
  return 0;
}