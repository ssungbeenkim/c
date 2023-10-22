/*
exec() 함수는 기존 프로세스를 새로운 프로세스로 재사용한다.
이미 만들어진 프로세스의 구조를 재사용하는 것이다.
코드 영역의 기존 내용을 지우고 새로운 코드로 대체
데이터 영역에는 새로운 변수로 채워지고, 스택 영역이 리셋된다.
PCB의 PPID, CPID, UID, GID, SID, TTY, NICE, SIGNAL, FD, UMASK 등의 정보는 그대로
유지되지만 카운터 레지스터 값을 비롯한 각종 레지스터와 사용한 파일 정보는
리셋된다.
 */

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
    execl("/bin/ls", "ls", "-al", NULL);
    printf("This line should not be printed");
  } else {
    wait(NULL)  // 자식 프로세스가 종료될 때까지 기다린다.
        printf("Parent process");
    exit(0);
  }

  return 0;
}