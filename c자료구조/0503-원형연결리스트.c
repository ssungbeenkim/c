#include <stdio.h>
#include <stdlib.h>

// 노드 구조체 정의
typedef struct Node {
  int data;
  struct Node* next;
} Node;

// 원형 연결 리스트 구조체 정의
typedef struct CircularLinkedList {
  Node* head;
} CircularLinkedList;

// 원형 연결 리스트 초기화 함수
void initialize(CircularLinkedList* list) { list->head = NULL; }

// 노드 추가 함수
void append(CircularLinkedList* list, int data) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;

  if (list->head == NULL) {
    newNode->next = newNode;  // 자기 자신을 가리킴
    list->head = newNode;
  } else {
    Node* current = list->head;
    while (current->next != list->head) {
      current = current->next;
    }
    current->next = newNode;
    newNode->next = list->head;
  }
}

// 노드 삭제 함수
void removeNode(CircularLinkedList* list, int data) {
  if (list->head == NULL) {
    return;
  }

  Node* current = list->head;
  Node* prev = NULL;
  do {
    if (current->data == data) {
      if (prev == NULL) {  // 첫 번째 노드를 삭제
        Node* last = list->head;
        while (last->next != list->head) {
          last = last->next;
        }
        last->next = current->next;
        list->head = current->next;
      } else {
        prev->next = current->next;
      }
      free(current);
      return;
    }
    prev = current;
    current = current->next;
  } while (current != list->head);
}

// 원형 연결 리스트 출력 함수
void display(CircularLinkedList* list) {
  if (list->head == NULL) {
    printf("리스트가 비어 있습니다.\n");
    return;
  }

  Node* current = list->head;
  printf("리스트의 요소: ");
  do {
    printf("%d ", current->data);
    current = current->next;
  } while (current != list->head);
  printf("\n");
}

// 메모리 해제 함수
void destroy(CircularLinkedList* list) {
  if (list->head == NULL) {
    return;
  }

  Node* current = list->head;
  while (current->next != list->head) {
    Node* temp = current;
    current = current->next;
    free(temp);
  }
  free(current);
  list->head = NULL;
}

int main() {
  CircularLinkedList list;
  initialize(&list);

  append(&list, 1);
  append(&list, 2);
  append(&list, 3);

  display(&list);

  removeNode(&list, 2);

  display(&list);

  destroy(&list);

  return 0;
}
