// 8.11 예제 : 타일링 방법의 수 세기
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
int main(){
  int n;
  memset(cache, -1, sizeof(cache));
  scanf("%d", &n);
  printf("%d\n", tiling(n));
}
