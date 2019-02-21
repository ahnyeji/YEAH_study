// 8.1 이항계수
#include <cstdio>
// 재귀 ver.
int bino(int n, int r){
  // 기저사례 : n=r 혹은 r=0
  if(r==0 || n==r) return 1;
  return bino(n-1, r-1)+bino(n-1,r);
}

int main(){
  int n, r;
  scanf("%d %d", &n, &r);
  printf("%d\n", bino(n,r));
}
