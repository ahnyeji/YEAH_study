// 8.4 예제 : 최대 증가 부분 수열
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
// 동적 계획법 (2) ver.
int n;
// 인덱스 -1부터 100까지이므로
// cache[101]
int cache[101], s[100];
// S[start]에서 시작하는 증가 부분 수열 중 최대 길이 반환
int lis3(int start){
  // 기저사례 없음
  // 입력 받는 값은 -1부터이지만
  // 배열의 인덱스는 0부터이므로
  // start+1을 사용한다
  int& ret = cache[start+1];
  if(ret != -1) return ret;
  // 항상 s[start]는 있으므로 길이는 최하 1
  ret = 1;
  for(int next=start+1; next<n; next++){
    if(start == -1 || s[start]<s[next]){
      ret = max(ret, lis3(next)+1);
    }
  }
  return ret;
}
int main(){
  // cache 배열 -1로 초기화
  memset(cache, -1, sizeof(cache));
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  // 시작 인덱스 -1로 고정
  printf("%d\n", lis3(-1)-1);
}
