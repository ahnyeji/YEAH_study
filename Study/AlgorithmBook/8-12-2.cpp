// 8.12 문제 : 비대칭 타일링 (2) 직접 해보기
#include <cstdio>
#include <string.h>
const int MOD = 1000000007;
int cache[101];
// 2*width 크기의 사각형을 채우는 방법의 수를
// MOD로 나눈 나머지 반환
int tiling(int width){
  // 기저사례 : width가 1 이하
  if(width <= 1) return 1;
  // 메모이제이션
  int& ret = cache[width];
  if(ret != -1) return ret;
  return ret = (tiling(width-2)+tiling(width-1))%MOD;
}

int cache2[101];
// 2*width 크기의 사각형을 채우는 비대칭 방법의 수 반환
int asymmetric2(int width){
  // 기저 사례 : 너비가 2 이하인 경우
  if(width <= 2) return 0;
  // 메모이제이션
  int& ret = cache2[width];
  if(ret != -1) return ret;
  // 양 쪽 끝이 대칭인 경우
  ret = asymmetric2(width-2) % MOD; // 세로타일링
  ret = (ret + asymmetric2(width-4)) % MOD; // 가로타일링
  // 양 쪽 끝이 비대칭인 경우
  ret = (ret + tiling(width-3)) % MOD; // 세로&가로
  ret = (ret + tiling(width-3)) % MOD; // 가로&세로
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    int n;
    memset(cache, -1, sizeof(cache));
    memset(cache2, -1, sizeof(cache2));
    scanf("%d", &n);
    printf("%d\n", asymmetric2(n));
  }
}
