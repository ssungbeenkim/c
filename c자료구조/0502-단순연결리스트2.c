#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {
  char data[4];
  struct ListNode* link;
} listNode;

typedef struct {
  listNode* head;
} linkedList_h;

linkedList_h* createLinkedList_h(void) {
  linkedList_h* L;
  L = (linkedList_h*)malloc(sizeof(linkedList_h));
  L->head = NULL;
  return L;
}

void freeLinkedList_h(linkedList_h* L) {
  listNode* p;
  while (L->head != NULL) {
    p = L->head;
    L->head = L->head->link;
    free(p);
    p = NULL;
  }
}

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

void insertFirstNode(linkedList_h* L, char* x) {
  listNode* newNode;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  newNode->link = L->head;
  L->head = newNode;
}

// L의 Pre 뒤에 x를 삽입
void insertMiddleNode(linkedList_h* L, listNode* pre, char* x) {
  listNode* newNode;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  if (L->head == NULL) {  // 비어있을 경우 삽입.
    newNode->link = NULL;
    L->head = newNode;
  } else if (pre == NULL) {  // pre가 null일 경우 첫 요소로 삽입.
    newNode->link = L->head;
    L->head = newNode;
  } else {
    newNode->link = pre->link;
    pre->link = newNode;
  }
}

void insertLastNode(linkedList_h* L, char* x) {
  listNode* newNode;
  listNode* temp;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  newNode->link = NULL;
  if (L->head == NULL) {
    L->head = newNode;
    return;
  }

  temp = L->head;
  while (temp->link != NULL) temp = temp->link;
  temp->link = newNode;
}

void deleteNode(linkedList_h* L, listNode* p) {
  listNode* pre;
  if (L->head == NULL) return;
  if (L->head->link == NULL) {
    free(L->head);

    L->head = NULL;

    return;
  } else if (p == NULL)
    return;
  else {
    pre = L->head;
    while (pre->link != p) {
      pre = pre->link;
    }
    pre->link = p->link;
    free(p);
  }
}

listNode* searchNode(linkedList_h* L, char* x) {
  listNode* temp;
  temp = L->head;
  while (temp != NULL) {
    if (strcmp(temp->data, x) == 0)  // string compare. 같으면 0을 출력함.
      return temp;
    else
      temp = temp->link;
  }
  return temp;
}

void reverse(linkedList_h* L) {
  listNode* p;
  listNode* q;
  listNode* r;

  p = L->head;
  q = NULL;
  // r = NULL; // 없어도 됨

  while (p != NULL) {  // *
    r = q;
    q = p;
    p = p->link;
    q->link = r;
  }
  L->head = q;
}

int main(void) {
  linkedList_h* L;
  listNode* p;
  L = createLinkedList_h();

  printf("(1) 리스트에서 월수일 노드 삽입 \n");
  insertLastNode(L, "월");
  insertLastNode(L, "수");
  insertLastNode(L, "일");
  printList(L);

  printf("\n(2) 리스트에서 수 노드 탐색! \n");
  p = searchNode(L, "수");
  if (p == NULL)
    printf("찾는 데이터 없음 \n");
  else
    printf("[%s]를 찾았습니다. \n", p->data);

  printf("\n(3) 리스트의 수 뒤에 금 노드 삽입! \n");
  insertMiddleNode(L, p, "금");
  printList(L);

  printf("\n(4) 리스트에서 일 노드 삭제하기! \n");
  p = searchNode(L, "일");
  deleteNode(L, p);
  printList(L);

  printf("\n(5) 리스트 순서를 역순으로 바꾸기! \n");
  reverse(L);
  printList(L);

  freeLinkedList_h(L);
  getchar();

  return 0;
}