#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 9999, SWITCHES = 10, CLOCKS = 16;
int button[10][16];
void setButton(){
  for(int i=0; i<10; i++){
    for(int j=0; j<16; j++){
      if(i==0 && (j==0 || j==1 || j==2)){
        button[i][j]=1;
      }
      if(i==1 && (j==3 || j==7 || j==9 || j==11)){
        button[i][j]=1;
      }
      if(i==2 && (j==4 || j==10 || j==14 || j==15)){
        button[i][j]=1;
      }
      if(i==3 && (j==0 || j==4 || j==5 || j==6 || j==7)){
        button[i][j]=1;
      }
      if(i==4 && (j==6 || j==7 || j==8 || j==10 || j==12)){
        button[i][j]=1;
      }
      if(i==5 && (j==0 || j==2 || j==14 || j==15)){
        button[i][j]=1;
      }
      if(i==6 && (j==3 || j==14 || j==15)){
        button[i][j]=1;
      }
      if(i==7 && (j==4 || j==5 || j==7 || j==14 || j==15)){
        button[i][j]=1;
      }
      if(i==8 && (j==1 || j==2 || j==3 || j==4 || j==5)){
        button[i][j]=1;
      }
      if(i==9 && (j==3 || j==4 || j==5 || j==9 || j==13)){
        button[i][j]=1;
      }
    }
  }
}
// 모든 시계가 12시를 가리키는 지 확인
bool aligned(const vector<int>& clock){
  for(int i=0; i<CLOCKS; i++){
    if(clock[i]!=12){
      return false;
    }
  }
  return true;
}
// 번호가 sw인 스위치 누르기
void click(vector<int>& clock, int sw){
  for(int cl=0; cl<CLOCKS; cl++){
    if(button[sw][cl]==1){
      clock[cl]+=3;
      // 시간은 3, 6, 9, 12로만 이루어짐
      if(clock[cl] == 15) clock[cl] = 3;
    }
  }
}
// clock : 16개 시계들의 현재 상태
// sw : 이번에 누를 스위치의 번호
// 위의 두 매개변수가 주어질 때, 남은 스위치 눌러서
// clock을 모두 12시로 맞출 수 있는 최소 횟수 반환
// 불가능할 경우 INF 이상의 큰 수 반환
int solve(vector<int>& clock, int sw){
  // 이미 모든 스위치를 눌렀을 때
  if(sw == SWITCHES) return aligned(clock)? 0 : INF;
  int ret = INF;
  // 하나의 스위치를 누르는 4가지 경우
  for(int cnt = 0; cnt<4; cnt++){
    ret = min(ret, cnt+solve(clock, sw+1));
    click(clock, sw);
  }
  return ret;
}

int main(){
  setButton();
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    vector<int> clock;
    for(int j=0; j<16; j++){
      int tmp;
      scanf("%d", &tmp);
      clock.push_back(tmp);
    }
    int ans = solve(clock, 0);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
  }
}
