#include <stdio.h>
#include <stdlib.h>

// 8*6 2차원 배열을 동적 메모리로 할당한다.

int main(void) {
  int i, x, y;
  int **pptr = (int **)malloc(sizeof(int *) * 8);
  // pptr에 동적 메모리를 할당하고 int 포인터형으로 casting 하여 그 첫주소를
  // 할당한다.
  for (i = 0; i < 8; i++) {
    *(pptr + i) = (int *)malloc(sizeof(int) * 6);
    // 이중포인터의 각 값에 int type의 동적 메모리의 첫 주소를 할당한다.
  }
  for (y = 0; y < 8; y++) {
    for (x = 0; x < 6; x++) {
      *(*(pptr + y) + x) = 6 * y + x;
    }
  }
  for (y = 0; y < 8; y++) {
    for (x = 0; x < 6; x++) {
      printf("%3d", *(*(pptr + y) + x));
    }
    printf("\n");
  }
  for (y = 0; y < 8; y++) {
    free(*(pptr + y));
  }
  return 0;
}

/*
참고:
포인터와 2차원 배열의 관계:
https://blog.naver.com/PostView.naver?blogId=sharonichoya&logNo=220487596658&categoryNo=22&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=&from=postList&userTopListOpen=true&userTopListCount=30&userTopListManageOpen=false&userTopListCurrentPage=1
* 2차원 배열은 1차원 배열을 여러개 가지고 있는 것이다.
* 2차원 배열의 각각의 원소들은 1차원 배열을 가지고 있다.
* 정수들의 배열을 할당하려면 포인터가 필요하다. 포인터의 배열을 할당하려면?
당연히 포인터의 포인터타입이 필요한 것이다.
2차원 배열 동적메모리 할당:
https://blog.naver.com/PostView.naver?blogId=sharonichoya&logNo=220529804336&categoryNo=22&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=&from=postList&userTopListOpen=true&userTopListCount=30&userTopListManageOpen=false&userTopListCurrentPage=1
 */