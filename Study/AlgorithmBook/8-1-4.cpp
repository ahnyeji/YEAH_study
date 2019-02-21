// 8.1 예제 : 외발 뛰기
#include <cstdio>
// 재귀 ver.
int n, board[100][100];
bool jump(int y, int x){
  // 기저사례 : 게임판을 벗어난 경우
  if(y>=n || x>=n) return false;
  // 기저사례 : 맨 마지막 칸에 도착한 경우
  if(y==n-1 && x==n-1) return true;
  int jumpSize = board[y][x];
  return jump(y+jumpSize, x) || jump(y, x+jumpSize);
}

int main(){
  scanf("%d", &n);
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      scanf("%d", &board[i][j]);
    }
  }
  if(jump(0,0)){
    printf("Success\n");
  }
  else{
    printf("Fail\n");
  }
}
