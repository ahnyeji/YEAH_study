#include <cstdio>
// n은 자연수
//1+2+...+n 구하는 함수
int fastSum(int n){
  // 기저사례
  if(n==1) return 1;
  // 홀수일 때 절반으로 나누어 떨어지지 않으니
  // n을 따로 더하고 n-1까지의 합을 재귀 호출
  if(n%2==1) return fastSum(n-1)+n;
  return 2*fastSum(n/2)+(n/2)*(n/2);
}

int main(){
  int N;
  scanf("%d", &N);
  printf("%d\n", fastSum(N));
}
