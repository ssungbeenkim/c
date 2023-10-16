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
  linkedList_h* CL;
  CL = (linkedList_h*)malloc(sizeof(linkedList_h));
  CL->head = NULL;
  return CL;
}

void printList(linkedList_h* CL) {
  listNode* p;
  printf("CL = (");
  p = CL->head;

  if (p == NULL) {  // 첫 요소일 경우
    printf(")\n");
    return;
  }
  do {
    printf("%s", p->data);
    p = p->link;
    if (p != CL->head) printf(", ");
  } while (p != CL->head);
  printf(")\n");
}

void insertFirstNode(linkedList_h* CL, char* x) {
  listNode *newNode, *temp;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  if (CL->head == NULL) {
    CL->head = newNode;
    newNode->link = newNode;
  } else {
    temp = CL->head;
    while (temp->link != CL->head) temp = temp->link;
    newNode->link = temp->link;
    temp->link = newNode;
    CL->head = newNode;
  }
}

void insertMiddleNode(linkedList_h* CL, listNode* pre, char* x) {
  listNode* newNode;
  newNode = (listNode*)malloc(sizeof(listNode));
  strcpy(newNode->data, x);
  if (CL->head == NULL) {
    CL->head = newNode;
    newNode->link = newNode;
  } else {
    newNode->link = pre->link;
    pre->link = newNode;
  }
}

void deleteNode(linkedList_h* CL, listNode* old) {
  listNode* pre;
  if (CL->head == NULL) return;
  if (CL->head->link == CL->head) {
    free(CL->head);
    CL->head = NULL;
    return;
  } else if (old == NULL)
    return;
  else {
    pre = CL->head;
    while (pre->link != old) {
      pre = pre->link;
    }
    pre->link = old->link;
    if (old == CL->head) CL->head = old->link;
    free(old);
  }
}

listNode* searchNode(linkedList_h* CL, char* x) {
  listNode* temp;
  temp = CL->head;
  if (temp == NULL) return NULL;
  do {
    if (strcmp(temp->data, x) == 0)
      return temp;
    else
      temp = temp->link;
  } while (temp != CL->head);
  return NULL;
}

int main(void) {
  linkedList_h* CL;
  listNode* p;

  CL = createLinkedList_h();
  printf("(1) 원형 연결 리스트 생성!\n");
  printList(CL);

  printf("\n(2) 원형 연결 리스트에 [첫] 삽입!\n");
  insertFirstNode(CL, "첫");
  printList(CL);

  printf("\n(3) 원형 연결 리스트에 [첫] 다음에 [두] 삽입!\n");
  p = searchNode(CL, "첫");
  insertMiddleNode(CL, p, "두");
  printList(CL);

  printf("\n(4) 원형 연결 리스트에 [두] 다음에 [세] 삽입!\n");
  p = searchNode(CL, "두");
  insertMiddleNode(CL, p, "세");
  printList(CL);

  printf("\n(5) 원형 연결 리스트에서 [두] 삭제!\n");
  p = searchNode(CL, "두");
  deleteNode(CL, p);
  printList(CL);
  getchar();
  return 0;
}
