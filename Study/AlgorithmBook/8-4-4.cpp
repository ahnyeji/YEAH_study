// 8.4 예제 : 최대 증가 부분 수열
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
// 동적 계획법 ver. 1
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
  memset(cache, -1, sizeof(cache));
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    scanf("%d", &s[i]);
  }
  printf("%d\n", lis2(0));
}
