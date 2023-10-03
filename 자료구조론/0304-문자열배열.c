// 배열 https://studyc.tistory.com/14 
// c언어 문자열, 초기화 https://m.blog.naver.com/PostView.naver?blogId=sharonichoya&logNo=220488567828&proxyReferer= 

#include <stdio.h>

int main() {
// 문자열을 입력받아 배열에 저장한 후 길이를 계산해서 출력해본다. 
    int i, length = 0;
    char str[50];
    printf("문자열을 입력하세요 : ");
    // gets(str);  // 문자열을 입력받아 str에 저장. 
    fgets(str, sizeof(str), stdin); // gets는 보안상의 문제로 인해 사용을 권장하지 않음
    printf("입력한 문자열은 \"");
    for (i = 0; str[i]; i++) {
      printf("%c", str[i]);
      length += 1;
    }
    printf("\" 입니다.\n");
    printf("\n\n입력된 문자열의 길이 = %d\n", length);
    // 마지막에 종료문자로 NULL이 들어가기 때문에 length에는 1이 더해진다.
    return 0;
}
