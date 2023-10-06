#include  <stdio.h> 

int main(void) {
  FILE *fp = NULL;
  fp = fopen("test.txt", "w");

  if(fp == NULL) {
    printf("파일 열기에 실패했습니다.\n");
  } else {
    printf("파일 열기에 성공했습니다.\n");
  }
  fputc("H",fp);
  fputc("e",fp);
  fputc("l",fp);
  fputc("l",fp);
  fputc("o",fp);
  fclose(fp);
  return 0;
}