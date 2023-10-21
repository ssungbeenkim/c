#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int pid;

  pid = fork();

  if (pid < 0) {
    printf("Error");
    exit(-1);
  } else if (pid == 0) {
    printf("Child process");
    exit(0);
  } else {
    printf("Parent process");
    exit(0);
  }

  return 0;
}

/*
fork() 를 호출하면 현재 프로세스와 동일한 내용의 자식 프로세스를 생성
자식 프로세스는 fork() 함수 이후의 코드부터 실행
부모 프로세스에 0 이상의 PID 가 반환되고, 자식 프로세스에는 0 이 반환된다.
0 보다 작은 값이 반환되면 fork() 함수 호출에 실패한 것이다.
 */