#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

typedef struct stackNode {
  element data;
  struct stackNode* link;
} stackNode;

stackNode* top;

void push(element item);
element pop();
int isStackEmpty();

int testPair(char* exp) {
  char symbol, open_pair;
  int i, length = strlen(exp);
  top = NULL;

  for (i = 0; i < length; i++) {
    symbol = exp[i];
    switch (symbol) {
      case '(':
      case '[':
      case '{':
        push(symbol);
        break;
      case ')':
      case ']':
      case '}':
        if (isStackEmpty())
          return 0;
        else {
          open_pair = pop();
          if ((open_pair == '(' && symbol != ')') ||
              (open_pair == '[' && symbol != ']') ||
              (open_pair == '{' && symbol != '}'))
            return 0;
          else
            break;
        }
    }
  }
  if (top == NULL)
    return 1;
  else
    return 0;
}

void push(element item) {
  stackNode* temp = (stackNode*)malloc(sizeof(stackNode));

  temp->data = item;
  temp->link = top;
  top = temp;
}

element pop() {
  element item;
  stackNode* temp = top;

  if (isStackEmpty()) {
    printf("\n\n Stack is empty !\n");
    return ' ';
  } else {
    item = temp->data;
    top = temp->link;
    free(temp);
    return item;
  }
}

int isStackEmpty() { return top == NULL; }

void printStack() {
  stackNode* p = top;
  printf("\n STACK [ ");
  while (p) {
    printf("%c ", p->data);  // 수정: %d -> %c
    p = p->link;
  }
  printf("] ");
}

int main(void) {
  char* correctExpression = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4";
  char* incorrectExpression = "{(A+B)-3}*5+[{cos(x+y)+7}-1]*4]";

  printf("Correct Expression: %s\n", correctExpression);
  printf("Incorrect Expression: %s\n", incorrectExpression);

  if (testPair(correctExpression) == 1)
    printf("\n\nThe parentheses in the expression are used correctly!\n");
  else
    printf("\n\nThere is a mismatch in the parentheses of the expression!\n");

  if (testPair(incorrectExpression) == 1)
    printf("\n\nThe parentheses in the expression are used correctly!\n");
  else
    printf("\n\nThere is a mismatch in the parentheses of the expression!\n");

  return 0;
}
