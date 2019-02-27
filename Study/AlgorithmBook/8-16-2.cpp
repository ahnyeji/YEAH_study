// 8.16 문제 : 두니발 박사 (2) 반대 방향에서 풀기
#include <cstdio>
#include <string.h>
int n, d, p, q;
double cache[51][101];
// connected[i][j] = 마을 i,j 연결 여부
// deg[i] = 마을 i와 연결된 마을의 개수
int connected[51][51], deg[51];
double search3(int here, int days){
  // 기저사례 : 0일째
  if(days==0) return (here==p? 1.0 : 0.0);
  // 메모이제이션
  double& ret = cache[here][days];
  if(ret > -0.5) return ret;
  ret = 0.0;
  for(int there=0; there<n; there++){
    if(connected[here][there]){
      ret += search3(there, days-1)/deg[there];
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
      printf("%.8lf ",search3(q, d));
    }
    printf("\n");
  }
}
