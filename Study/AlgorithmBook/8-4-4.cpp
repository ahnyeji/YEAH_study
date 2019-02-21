// 8.4 예제 : 최대 증가 부분 수열
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
// 동적 계획법 (1) ver.
int n;
int cache[100], s[100];
int lis2(int start){
  // 기저사례 없음
  int& ret = cache[start];
  if(ret != -1) return ret;
  // 항상 s[start]는 있으므로 길이는 최하 1
  ret = 1;
  for(int next=start+1; next<n; next++){
    if(s[start]<s[next]){
      ret = max(ret, lis2(next)+1);
    }
  }
  return ret;
}
int main(){
  // cache 배열 -1로 초기화
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  // 모든 인덱스에서 시작하도록 계산해봐야 함
  int maxLen=0;
  for(int begin=0; begin<n; begin++){
    // 메모리 초기화!!
    memset(cache, -1, sizeof(cache));
    maxLen = max(maxLen, lis2(begin));
  }
  printf("%d\n", maxLen);
}
