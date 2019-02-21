// 8.1 예제 : 외발 뛰기
#include <cstdio>
#include <string.h>
// 동적 계획법 ver.
int n, board[100][100];
int cache[100][100];
int jump2(int y, int x){
  // 기저사례 : 게임판을 벗어난 경우
  if(y>=n || x>=n) return 0;
  // 기저사례 : 맨 마지막 칸에 도착한 경우
  if(y==n-1 && x==n-1) return 1;
  // 메모이제이션
  int& ret = cache[y][x];
  // 값이 -1이 아닌 경우 이미 계산된 값 반환
  if(ret != -1) return ret;
  int jumpSize = board[y][x];
  return ret = (jump2(y+jumpSize, x) || jump2(y, x+jumpSize));
}

int main(){
  scanf("%d", &n);
  memset(cache, -1, sizeof(cache));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &board[i][j]);
    }
  }
  if(jump2(0,0)){
    printf("Success\n");
  }
  else{
    printf("Fail\n");
  }
}
