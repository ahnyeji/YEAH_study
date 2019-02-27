// 8.14 문제 : 폴리오미노
#include <cstdio>
#include <string.h>
const int MOD = 10*1000*1000;
int cache[101][101];
// n개의 정사각형으로 이루어져있고,
// 맨 위 가로줄에 first개의 정사각형을 포함하는
// 폴리오미노의 개수 반환
int poly(int n, int first){
  // 기저사례 : n==first
  if(n==first) return 1;
  // 메모이제이션
  int& ret = cache[n][first];
  if(ret != -1) return ret;
  ret = 0;
  for(int second = 1; second <= n-first; second++){
    int add = second+first-1;
    add *= poly(n-first, second);
    add %= MOD;
    ret += add;
    ret %= MOD;
  }
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    memset(cache, -1, sizeof(cache));
    int n;
    scanf("%d", &n);
    int ans = 0;
    // first가 1일 때 부터 n일 때 까지 모두 더해야 답
    for(int j=1; j<=n; j++){
      ans += poly(n,j);
      ans %= MOD;
    }
    printf("%d\n", ans);
  }
}
