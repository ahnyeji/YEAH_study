#include <cstdio>
#include <string.h>

int student[10][10];
int n, m;

int findPair(int taken[10]){
  // 가장 번호가 빠른 학생 찾기
  int idx = -1;
  for(int i=0; i<n; i++){
    if(!taken[i]){
      idx = i;
      break;
    }
  }
  // 기저 사례 : 모든 학생이 짝을 찾을 경우 종료
  if(idx == -1) return 1;
  int ret = 0;
  // 위에서 찾은 학생(idx)와 짝지을 학생을 결정
  for(int i = idx+1; i<n; i++){
    if(!taken[i] && student[idx][i]){
      // 짝 지었음 표시
      taken[idx]=1;
      taken[i]=1;
      // 둘을 짝지은 후 남은 학생들 마저 짝 짓기
      ret += findPair(taken);
      // 다른 학생과 짝을 지을 경우를 찾기 위해
      //원 상태로 되돌리기
      taken[idx]=0;
      taken[i]=0;
    }
  }
  return ret;
}

int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    scanf("%d %d", &n, &m);
    memset(student, 0, sizeof(student));
    for(int j=0; j<m; j++){
      int a, b;
      scanf("%d %d", &a, &b);
      student[a][b]=1;
      student[b][a]=1;
    }
    int start[10];
    printf("%d\n", findPair(start));
  }
}
