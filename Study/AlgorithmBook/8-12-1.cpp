// 8.12 문제 : 비대칭 타일링 (1) 대칭성 활용
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

// 2*width 크기의 사각형을 채우는 비대칭 방법의 수 반환
// 전체 타일링 - 대칭 타일링
int asymmetric(int width){
  // width가 홀수인 경우
  if(width%2==1){
    return (tiling(width)-tiling(width/2)+MOD)%MOD;
  }
  int ret = tiling(width);
  // 처음부터 절반이 대칭인 경우
  ret = (ret-tiling(width/2)+MOD)%MOD;
  // 정가운데가 가로 타일 2개인 경우
  ret = (ret-tiling(width/2-1)+MOD)%MOD;
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    int n;
    memset(cache, -1, sizeof(cache));
    scanf("%d", &n);
    printf("%d\n", asymmetric(n));
  }
}
