#include <cstdio>
#include <vector>
using namespace std;

int c, h, w;
// 블록 모양에 따른 방향 표시
// 숫자는 y, x 순서이다
const int yx[4][3][2]={
  {{0,0},{1,0},{0,1}},
  {{0,0},{0,1},{1,1}},
  {{0,0},{1,0},{1,1}},
  {{0,0},{1,0},{1,-1}}
};
// 주어진 모양의 블록 놔보기
// delta == 1이면 덮고, -1이면 없앤다
bool set(vector<vector<int> >& board, int y, int x, int type, int delta){
  bool ok = true;
  // i는 L자 모양의 블록 한 칸 한 칸을 의미
  for(int i=0; i<3; i++){
    const int ny = y + yx[type][i][0];
    const int nx = x + yx[type][i][1];
    // 주어진 판을 벗어나는 경우 실패
    if(ny<0 || ny >= board.size() || nx < 0 || nx > board[0].size()){
      ok = false;
    }
    // 먼저 블록을 놓고 (+= 부분)
    // 블록이 겹치는 경우 (검은 칸 또는 이미 놓인 칸) 실패
    else if((board[ny][nx] += delta) > 1){
      ok = false;
    }
  }
  return ok;
}
// 판을 전부 덮을 수 있는 경우의 수를 반환
int find(vector<vector<int> >& board){
  // 흰 칸 중 가장 위, 왼쪽 칸 찾기
  int x=-1, y=-1;
  for(int i=0; i<board.size(); i++){
    for(int j=0; j<board[0].size(); j++){
      // board[i][j]==0일 때 흰 칸
      if(board[i][j]==0){
        x=j; y=i; break;
      }
    }
    // 이중 for문의 탈출을 위해 필요한 부분
    if(y!=-1) break;
  }
  // 판이 이미 다 덮인 경우 종료
  if(y==-1) return 1;
  int ret = 0;
  // 네 가지 방법으로 블록 놓기
  for(int dir=0; dir<4; dir++){
    // 블록 놓을 수 있으면 놓고
    // 재귀로 다음 칸 마저 채우기
    if(set(board, y, x, dir, 1)){
      ret += find(board);
    }
    // 덮었던 블록 다시 치워서 다른 모양 확인
    set(board, y, x, dir, -1);
  }
  return ret;
}

int main(){
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    scanf("%d %d", &h, &w);
    char ip[21][21]={};
    for(int j=0; j<h; j++){
      scanf("%s", ip[j]);
    }
    int cnt = 0;
    vector<vector<int> > board;
    for(int j=0; j<h; j++){
      vector<int> tmp;
      for(int k=0; k<w; k++){
        if(ip[j][k]=='.'){
          cnt++;
          tmp.push_back(0);
        }
        else{
          tmp.push_back(1);
        }
      }
      board.push_back(tmp);
    }
    int ans = 0;
    if(cnt%3==0){
      ans = find(board);
    }
    printf("%d\n", ans);
  }
}
