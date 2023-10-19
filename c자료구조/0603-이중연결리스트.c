#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*--- 회원 데이터 ---*/
typedef struct {
  int no;         // 번호
  char name[20];  // 이름
} Member;

#define MEMBER_NO 1    // 번호를 나타내는 상수
#define MEMBER_NAME 2  // 이름을 나타내는 상수

/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member* x, const Member* y);

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member* x, const Member* y);

/*--- 회원 데이터를 출력(줄 바꿈 없음) ---*/
void PrintMember(const Member* x);

/*--- 회원 데이터를 출력(줄 바꿈 있음) ---*/
void PrintLnMember(const Member* x);

/*--- 회원 데이터를 읽음 ---*/
Member ScanMember(const char* message, int sw);

/*--- 회원 번호 비교 함수 ---*/
int MemberNoCmp(const Member* x, const Member* y) {
  return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;
}

/*--- 회원 이름 비교 함수 ---*/
int MemberNameCmp(const Member* x, const Member* y) {
  return strcmp(x->name, y->name);
}

/*--- 회원 데이터(번호와 이름)를 출력(줄 바꿈 없음) ---*/
void PrintMember(const Member* x) { printf("%d %s", x->no, x->name); }

/*--- 회원 데이터(번호와 이름)를 출력(줄 바꿈 있음) ---*/
void PrintLnMember(const Member* x) { printf("%d %s\n", x->no, x->name); }

/*--- 회원 데이터(번호와 이름)를 읽음 ---*/
Member ScanMember(const char* message, int sw) {
  Member temp;
  printf("%s하는 데이터를 입력하세요.\n", message);
  if (sw & MEMBER_NO) {
    printf("번호: ");
    scanf("%d", &temp.no);
  }
  if (sw & MEMBER_NAME) {
    printf("이름: ");
    scanf("%19s", temp.name, sizeof(temp.name));
  }
  return temp;
}

/*--- 메뉴 ---*/
typedef enum Menu {
  TERMINATE,
  INS_FRONT,
  INS_REAR,
  RMV_FRONT,
  RMV_REAR,
  PRINT_CRNT,
  RMV_CRNT,
  SRCH_NO,
  SRCH_NAME,
  PRINT_ALL,
  NEXT,
  PREV,
  CLEAR
} Menu;

/*--- 메뉴 선택 ---*/
Menu SelectMenu(void) {
  int ch;
  char* mstring[] = {
      "머리에 노드를 삽입",
      "꼬리에 노드를 삽입",
      "머리 노드를 삭제",
      "꼬리 노드를 삭제",
      "선택한 노드를 출력",
      "선택한 노드를 삭제",
      "번호로 검색",
      "이름으로 검색",
      "모든 노드를 출력",
      "선택한 노드를 뒤쪽으로",
      "선택한 노드를 앞쪽으로",
      "모든 노드를 삭제",
  };
  do {
    for (int i = TERMINATE; i < CLEAR; i++) {
      printf("(%2d) %-18.18s  ", i + 1, mstring[i]);
      if ((i % 3) == 2) putchar('\n');
    }
    printf("(0) 종료: ");
    scanf("%d", &ch, sizeof(ch));
  } while (ch < TERMINATE || ch > CLEAR);
  return (Menu)ch;
}

/*--- 노드 ---*/
typedef struct __node {
  Member data;          // 데이터
  struct __node* prev;  // 앞쪽 노드에 대한 포인터
  struct __node* next;  // 다음 노드에 대한 포인터
} Dnode;

/*--- 원형 이중 연결 리스트 ---*/
typedef struct {
  Dnode* head;  // 머리의 더미 노드에 대한 포인터
  Dnode* crnt;  // 선택한 노드에 대한 포인터
} Dlist;

/*--- 1개의 노드를 동적으로 생성 ---*/
static Dnode* AllocDnode(void) { return calloc(1, sizeof(Dnode)); }

/*--- 노드의 각 멤버값을 설정 ----*/
static void SetDnode(Dnode* n, const Member* x, const Dnode* prev,
                     const Dnode* next) {
  n->data = *x;    // 데이터
  n->prev = prev;  // 앞쪽 노드에 대한 포인터
  n->next = next;  // 다음 노드에 대한 포인터
}

/*--- 리스트가 비어 있는지 검사 ---*/
static int IsEmpty(const Dlist* list) { return list->head->next == list->head; }

/*--- 리스트를 초기화 ---*/
void Initialize(Dlist* list) {
  Dnode* dummyNode = AllocDnode();  // 더미 노드 생성
  list->head = list->crnt = dummyNode;
  dummyNode->prev = dummyNode->next = dummyNode;
}

/*--- 선택한 노드의 데이터를 출력 ---*/
void PrintCurrent(const Dlist* list) {
  if (IsEmpty(list))
    printf("선택한 노드가 없습니다.");
  else
    PrintMember(&list->crnt->data);
}

/*--- 선택한 노드의 데이터를 출력(줄 바꿈 문자 추가) ---*/
void PrintLnCurrent(const Dlist* list) {
  PrintCurrent(list);
  putchar('\n');
}

/*--- compare 함수로 x와 일치하는 노드를 검색 ---*/
Dnode* Search(Dlist* list, const Member* x,
              int compare(const Member* x, const Member* y)) {
  Dnode* ptr = list->head->next;
  while (ptr != list->head) {
    if (compare(&ptr->data, x) == 0) {
      list->crnt = ptr;
      return ptr;  // 검색 성공
    }
    ptr = ptr->next;
  }
  return NULL;  // 검색 실패
}

/*--- 모든 노드의 데이터를 리스트 순서대로 출력 ---*/
void Print(const Dlist* list) {
  if (IsEmpty(list))
    puts("노드가 없습니다.");
  else {
    Dnode* ptr = list->head->next;
    puts("【모두 보기】");
    while (ptr != list->head) {
      PrintLnMember(&ptr->data);
      ptr = ptr->next;  // 다음 노드 선택
    }
  }
}

/*--- 모든 노드의 데이터를 리스트 순서의 역순으로 출력 ---*/
void PrintReverse(const Dlist* list) {
  if (IsEmpty(list))
    puts("노드가 없습니다.");
  else {
    Dnode* ptr = list->head->prev;

    puts("【모두 보기】");
    while (ptr != list->head) {
      PrintLnMember(&ptr->data);
      ptr = ptr->prev;  // 앞쪽 노드 선택
    }
  }
}

/*--- 선택한 노드를 다음으로 진행 ---*/
int Next(Dlist* list) {
  if (IsEmpty(list) || list->crnt->next == list->head)
    return 0;  // 진행할 수 없음
  list->crnt = list->crnt->next;
  return 1;
}

/*--- 선택한 노드를 앞쪽으로 진행 ---*/
int Prev(Dlist* list) {
  if (IsEmpty(list) || list->crnt->prev == list->head)
    return 0;  // 되돌아갈 수 없음
  list->crnt = list->crnt->prev;
  return 1;
}

/*--- p가 가리키는 노드 바로 다음 노드를 삽입 ---*/
void InsertAfter(Dlist* list, Dnode* p, const Member* x) {
  Dnode* ptr = AllocDnode();
  Dnode* nxt = p->next;

  p->next = p->next->prev = ptr;
  SetDnode(ptr, x, p, nxt);
  list->crnt = ptr;  // 삽입한 노드를 선택
}

/*--- 머리에 노드를 삽입 ---*/
void InsertFront(Dlist* list, const Member* x) {
  InsertAfter(list, list->head, x);
}

/*--- 꼬리에 노드를 삽입 ---*/
void InsertRear(Dlist* list, const Member* x) {
  InsertAfter(list, list->head->prev, x);
}

/*--- p가 가리키는 노드를 삭제 ---*/
void Remove(Dlist* list, Dnode* p) {
  p->prev->next = p->next;
  p->next->prev = p->prev;
  list->crnt = p->prev;  // 삭제한 노드의 앞쪽 노드를 선택
  free(p);
  if (list->crnt == list->head) list->crnt = list->head->next;
}

/*--- 머리 노드를 삭제 ---*/
void RemoveFront(Dlist* list) {
  if (!IsEmpty(list)) Remove(list, list->head->next);
}

/*--- 꼬리 노드를 삭제 ---*/
void RemoveRear(Dlist* list) {
  if (!IsEmpty(list)) Remove(list, list->head->prev);
}

/*--- 선택한 노드를 삭제 ---*/
void RemoveCurrent(Dlist* list) {
  if (list->crnt != list->head) Remove(list, list->crnt);
}

/*--- 모든 노드를 삭제 ---*/
void Clear(Dlist* list) {
  while (!IsEmpty(list))  // 텅 빌 때까지
    RemoveFront(list);    // 머리 노드를 삭제
}

/*--- 원형 이중 연결 리스트 종료 ---*/
void Terminate(Dlist* list) {
  Clear(list);       // 모든 노드를 삭제
  free(list->head);  // 더미 노드를 삭제
}

/*--- 메인 ---*/
int main(void) {
  Menu menu;
  Dlist list;
  Initialize(&list);  // 원형 이중 연결 리스트를 초기화
  do {
    Member x;
    switch (menu = SelectMenu()) {
      /* 머리에 노드를 삽입 */
      case INS_FRONT:
        x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
        InsertFront(&list, &x);
        break;

      /* 꼬리에 노드를 삽입 */
      case INS_REAR:
        x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
        InsertRear(&list, &x);
        break;

      /* 머리 노드를 삭제 */
      case RMV_FRONT:
        RemoveFront(&list);
        break;

      /* 꼬리 노드를 삭제 */
      case RMV_REAR:
        RemoveRear(&list);
        break;

      /* 선택한 노드의 데이터를 출력 */
      case PRINT_CRNT:
        PrintLnCurrent(&list);
        break;

      /* 선택한 노드를 삭제 */
      case RMV_CRNT:
        RemoveCurrent(&list);
        break;

      /* 번호로 검색 */
      case SRCH_NO:
        x = ScanMember("검색", MEMBER_NO);
        if (Search(&list, &x, MemberNoCmp) != NULL)
          PrintLnCurrent(&list);
        else
          puts("그 번호의 데이터가 없습니다.");
        break;

      /* 이름으로 검색 */
      case SRCH_NAME:
        x = ScanMember("검색", MEMBER_NAME);
        if (Search(&list, &x, MemberNameCmp) != NULL)
          PrintLnCurrent(&list);
        else
          puts("그 이름의 데이터가 없습니다.");
        break;

      /* 모든 노드의 데이터를 출력 */
      case PRINT_ALL:
        Print(&list);
        break;

      /* 선택한 노드를 뒤쪽으로 진행 */
      case NEXT:
        Next(&list);
        break;

      /* 선택한 노드를 앞쪽으로 진행 */
      case PREV:
        Prev(&list);
        break;

      /* 모든 노드를 삭제 */
      case CLEAR:
        Clear(&list);
        break;
    }
  } while (menu != TERMINATE);
  Terminate(&list);  // 원형 이중 연결 리스트 종료

  return 0;
}
