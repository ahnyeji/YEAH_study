// 8.4 예제 : 삼각형 위의 최대 경로
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
// 최적화 동적 계획법 ver.
int n, tri[100][100];
int cache2[100][100];
// (y,x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로 반환
int path2(int y, int x){
  // 기저사례 : 맨 아래 줄까지 도달했을 경우
  if(y==n-1) return tri[y][x];
  // 메모이제이션
  int& ret = cache2[y][x];
  // 값이 -1이 아닌 경우 이미 계산된 값 반환
  if(ret != -1) return ret;
  return ret = max(path2(y+1, x+1), path2(y+1, x)) + tri[y][x];
}

int main(){
  scanf("%d", &n);
  memset(cache2, -1, sizeof(cache2));
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      scanf("%d", &tri[i][j]);
    }
  }
  printf("%d\n", path2(0,0));
}
