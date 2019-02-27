// 8.5 문제 : 합친 LIS
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
// 입력이 32비트 부호 있는 정수의 모든 값을 가질 수 있으므로
// 인위적인 최소치는 64비트여야 한다
const long long NEGINF = numeric_limits<long long>::min();
int n, m;
vector<int> A;
vector<int> B;
int cache[101][101];
// min(A[indexA], B[indexB]), max(A[indexA], B[indexB])로
// 시작하는 합친 증가 부분 수열의 최대 길이를 반환한다.
// 단, indexA==indexB==-1 혹은 A[indexA]!=B[indexB]라고 가정
int jlis(int indexA, int indexB){
  // 메모이제이션
  int& ret = cache[indexA+1][indexB+1];
  if(ret != -1) return ret;
  // A[indexA], B[indexB]가 이미 존재하므로 2개는 항상 있다
  ret = 0;
  long long a = (indexA == -1 ? NEGINF : A[indexA]);
  long long b = (indexB == -1 ? NEGINF : B[indexB]);
  long long maxElement = max(a, b);
  // 다음 원소 찾기
  for(int nextA = indexA+1; nextA < n; nextA++){
    if(maxElement < A[nextA]){
      ret = max(ret, jlis(nextA, indexB)+1);
    }
  }
  for(int nextB = indexB+1; nextB < m; nextB++){
    if(maxElement < B[nextB]){
      ret = max(ret, jlis(nextB, indexB)+1);
    }
  }
  return ret;
}

int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    memset(cache, -1, sizeof(cache));
    A.clear();
    B.clear();
    scanf("%d %d", &n, &m);
    int tmp;
    for(int j=0; j<n; j++){
      scanf("%d", &tmp);
      A.push_back(tmp);
    }
    for(int j=0; j<m; j++){
      scanf("%d", &tmp);
      B.push_back(tmp);
    }
    printf("%d\n", jlis(-1, -1));
  }
}
