// 8.7 문제 : 원주율 외우기
#include <cstdio>
#include <string.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int INF = 987654321;
string N;
// N[a..b]구간의 난이도 반환
int classify(int a, int b){
  // 숫자 조각 가져오기
  string M = N.substr(a, b-a+1);
  // 난이도 1
  // 첫 글자만으로 이루어진 문자열과 같음
  if(M==string(M.size(), M[0])) return 1;
  // 등차수열 확인
  bool progressive = true;
  for(int i=0; i<M.size()-1; i++){
    if((M[i+1]-M[i])!=(M[1]-M[0])){
      progressive = false;
    }
  }
  // 난이도 2
  // 등차수열 && 공차가 1 또는 -1
  if(progressive && ((M[1]-M[0])==1 || (M[1]-M[0])==-1)){
    return 2;
  }
  // 두 수가 번갈아 등장하는 지 확인
  bool alternating = true;
  for(int i=0; i<M.size(); i++){
    if(M[i]!=M[i%2]){
      alternating = false;
    }
  }
  if(alternating) return 4; // 난이도 4. 두 수 번갈아 등장
  if(progressive) return 5; // 난이도 5. 공차 절댓값 1 아닌 등차수열
  return 10; // 위의 난이도 제외하고 전부 난이도 10.
}
int cache[10002];
// 수열 N[begin]을 외우는 방법 중 난이도 최소 합 출력
int memorize(int begin){
  // 기저사례 : 수열의 끝에 도달
  if(begin == N.size()) return 0;
  // 메모이제이션
  int& ret = cache[begin];
  if(ret != -1) return ret;
  ret = INF;
  for(int L = 3; L<=5; L++){
    if(begin+L <= N.size()){
      ret = min(ret, memorize(begin+L)+classify(begin, begin+L-1));
    }
  }
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    memset(cache, -1, sizeof(cache));
    cin >> N;
    printf("%d\n", memorize(0));
  }
}
