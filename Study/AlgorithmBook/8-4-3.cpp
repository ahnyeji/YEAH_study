// 8.4 예제 : 최대 증가 부분 수열
#include <cstdio>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
// 완전 탐색 ver.
int lis(const vector<int>& A){
  // 기저사례 : A가 비어있을 때
  if(A.empty()) return 0;
  int ret = 0;
  for(int i=0; i<A.size(); i++){
    // 지금 보고 있는 수 다음 칸에
    // 나올 수 있는 모든 숫자를
    // 배열(벡터)로 만들어 전달
    vector<int> B;
    for(int j=i+1; j<A.size(); j++){
      if(A[i] < A[j]){
        B.push_back(A[j]);
      }
    }
    // 길이가 더 긴 쪽 선택
    ret = max(ret, 1+lis(B));
  }
  return ret;
}
int main(){
  int n;
  scanf("%d", &n);
  vector<int> ip;
  for(int i=0; i<n; i++){
    int tmp;
    scanf("%d", &tmp);
    ip.push_back(tmp);
  }
  printf("%d\n", lis(ip));
}
