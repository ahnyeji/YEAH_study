// 8.9 문제 : Quantization
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int INF = 987654321;
// A[] : 양자화 할 수열, 정렬된 상태
// pSum[] : A[]의 부분합 저장 (평균 구하기 위함)
// pSqSum[] : A[] 제곱의 부분합을 저장
int n;
int A[101], pSum[101], pSqSum[101];
// A를 정렬하고 각 부분합 계산
void precalc(){
  sort(A, A+n);
  pSum[0] = A[0];
  pSqSum[0] = A[0]*A[0];
  for(int i=1; i<n; i++){
    pSum[i] = pSum[i-1]+A[i];
    pSqSum[i] = pSqSum[i-1] + A[i]*A[i];
  }
}
// A[lo]..A[hi]구간을 하나의 숫자로 표현할 때 최소 오차 합 계산
int minError(int lo, int hi){
  // 부분합을 이용해 A[lo]부터 A[hi]까지의 합 구하기
  int sum = pSum[hi] - (lo == 0 ? 0 : pSum[lo-1]);
  int sqsum = pSqSum[hi] - (lo == 0 ? 0 : pSqSum[lo-1]);
  // 평균을 반올림 한 값으로 이 수들을 표현
  int m = int(0.5+(double)sum/(hi-lo+1));
  // sum (A[i]-m)^2 전개 결과를 부분 합으로 표현
  int ret = sqsum - 2*m*sum + m*m*(hi-lo+1);
  return ret;
}
int cache[101][11];
int quantize(int from, int parts){
  // 기저사례 : 모든 수를 다 양자화 했을 때
  if(from==n) return 0;
  // 기저사례 : 숫자는 아직 남았는데 더 묶을 수 없을 때
  // 아주 큰 값 반환
  if(parts == 0) return INF;
  int& ret = cache[from][parts];
  if(ret != -1) return ret;
  ret = INF;
  // 조각의 길이를 변화시켜가며 최소치 찾기
  for(int partSize = 1; from+partSize<=n; partSize++){
    ret = min(ret, minError(from, from+partSize-1) + quantize(from+partSize, parts-1));
  }
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    int s;
    memset(cache, -1, sizeof(cache));
    scanf("%d %d", &n, &s);
    for(int j=0; j<n; j++){
      scanf("%d", &A[j]);
    }
    precalc();
    printf("%d\n", quantize(0, s));
  }
}
