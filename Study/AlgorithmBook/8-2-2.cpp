// 8.2 문제 : 와일드카드
#include <cstdio>
#include <string.h>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
// 동적 계획법 (2) ver.
// -1 : 아직 계산되지 않음
// 1 : 대응됨
// 0 : 대응되지 않음
int cache[101][101];
// W : 패턴 , S : 문자열
string W, S;
// 와일드카드 패턴 W가 문자열 S에 대응되는지 여부 반환
bool matchMemoized(int w, int s){
  // 메모이제이션
  int& ret = cache[w][s];
  if(ret != -1) return ret;
  // W[w]와 S[s] 맞춰보기
  if(s<S.size() && w<W.size() && (W[w]=='?' || W[w]==S[s])){
    return ret = matchMemoized(w+1, s+1);
  }
  // 더이상 대응할 수 없으면 while문 종료 이유 확인
  // 2. 패턴 끝에 도착해서 끝난 경우 : 문자열도 끝났어야 참
  if(w==W.size()){
    return ret = (s==S.size());
  }
  // 4. *을 만나서 끝난 경우 : *에 몇 글자 대응해야 하나?
  if(W[w]=='*'){
    if(matchMemoized(w+1, s) || (s<S.size()&&matchMemoized(w, s+1))){
      return ret = 1;
    }
  }
  // 3. 이 외의 경우 모두 대응되지 않음
  return ret = 0;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    // cache 배열 -1로 초기화
    cin >> W;
    int n;
    scanf("%d", &n);
    for(int j=0; j<n; j++){
      memset(cache, -1, sizeof(cache));
      cin >> S;
      if(matchMemoized(0,0)){
        cout << S << "\n";
      }
    }
  }
}
