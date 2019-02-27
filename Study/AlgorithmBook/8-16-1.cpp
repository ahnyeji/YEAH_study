// 8.16 문제 : 두니발 박사 (1)
#include <cstdio>
#include <string.h>
int n, d, p, q;
// cache[][]는 -1로 초기화
double cache[51][101];
// connected[i][j] = 마을 i,j 연결 여부
// deg[i] = 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
// days일째에 here번 마을에 숨어있다고 가정
// 마지막 날에 q번 마을에 숨어있을 조건부 확률
double search2(int here, int days){
  // 기저사례 : d일이 지난 경우
  if(days==d) return (here==q? 1.0 : 0.0);
  // 메모이제이션
  double& ret = cache[here][days];
  if(ret > -0.5) return ret;
  ret = 0.0;
  for(int there=0; there<n; there++){
    if(connected[here][there]){
      ret += search2(there, days+1)/deg[here];
    }
  }
  return ret;
}
int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    memset(connected, 0, sizeof(connected));
    memset(deg, 0, sizeof(deg));
    scanf("%d %d %d", &n, &d, &p);
    for(int j=0; j<n; j++){
      for(int k=0; k<n; k++){
        scanf("%d", &connected[j][k]);
        if(connected[j][k]==1){
          deg[j]++;
        }
      }
    }
    int t;
    scanf("%d", &t);
    for(int j=0; j<t; j++){
      memset(cache, -1, sizeof(cache));
      scanf("%d", &q);
      printf("%.8lf ",search2(p, 0));
    }
    printf("\n");
  }
}
