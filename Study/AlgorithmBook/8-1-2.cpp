// 8.1 이항계수
#include <cstdio>
#include <string.h>
// 동적 계획법 ver.
// 값을 저장할 배열
int cache[30][30];
int bino2(int n, int r){
  // 기저사례 : n=r 혹은 r=0
  if(r==0 || n==r) return 1;
  // 배열을 직접 쓸 경우
  // index 입력에서 오류 발생 가능성 있으므로
  // 참조형 변수 활용
  int& ret = cache[n][r];
  // 저장된 값이 -1이 아니라면
  // 이미 계산된 값이니 곧장 반환
  if(ret != -1) return ret;
  return ret = bino2(n-1, r-1)+bino2(n-1,r);
}

int main(){
  int n, r;
  // cache 배열을 -1로 초기화
  memset(cache, -1, sizeof(cache));
  scanf("%d %d", &n, &r);
  printf("%d\n", bino2(n,r));
}
