// 8.4 예제 : 삼각형 위의 최대 경로
#include <cstdio>
#include <string.h>
#include <algorithm>
#define MAXN 1000
using namespace std;
// 단순 메모이제이션 ver.
int n, tri[100][100];
// MAXN : 한 칸에 들어갈 숫자의 최대치
int cache[100][100][MAXN*100+1];
// (y,x) 위치까지 내려오기 전에 만난 숫자의 합이 sum일 때
// 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로 반환
int path1(int y, int x, int sum){
  // 기저사례 : 맨 아래 줄까지 도달했을 경우
  if(y==n-1) return sum+tri[y][x];
  // 메모이제이션
  int& ret = cache[y][x][sum];
  // 값이 -1이 아닌 경우 이미 계산된 값 반환
  if(ret != -1) return ret;
  sum += tri[y][x];
  return ret = max(path1(y+1, x+1, sum), path1(y+1, x, sum));
}

int main(){
  scanf("%d", &n);
  memset(cache, -1, sizeof(cache));
  for(int i=0; i<n; i++){
    for(int j=0; j<i+1; j++){
      scanf("%d", &tri[i][j]);
    }
  }
  printf("%d\n", path1(0,0,0));
}
