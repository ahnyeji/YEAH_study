#include <cstdio>
#include <vector>
using namespace std;
// 각 판자의 높이를 저장하는 배열
vector<int> h;
// h[left..right] 구간에서 찾아낼 수 있는
// 가장 큰 직사각형의 넓이 반환
int solve(int left, int right){
  // 기저사례 : 판자가 하나 밖에 없을 때
  if(left == right) return h[left];
  // [left,mid], [mid+1,right]로 분할
  int mid = (left+right)/2;
  // 1. 왼쪽 절반에 최대 직사각형이 있는 경우와
  // 2. 오른쪽 절반에 최대 직사각형이 있는 경우 중
  // 최대값 찾기
  int ret = max(solve(left, mid), solve(mid+1, right));
  // 3. 양쪽에 걸쳐서 최대 직사각형이 있는 경우
  int lo = mid, hi = mid+1;
  // // 직사각형의 높이 저장
  int height = min(h[lo], h[hi]);
  // // [mid, mid+1]만 포함하는 너비 2인 사각형 고려
  ret = max(ret, height*2);
  // // 모든 판자를 확인할 때까지 확장
  while(left < lo || hi < right){
    // // 항상 높이가 더 높은 쪽으로 확장
    if(hi < right && (lo==left || h[lo-1]<h[hi+1])){
      hi++;
      height = min(height, h[hi]);
    }
    else{
      lo--;
      height = min(height, h[lo]);
    }
    // 확장 후 사각형의 넓이
    ret = max(ret, height*(hi-lo+1));
  }
  return ret;
}
int main(){
  int c, n;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    scanf("%d", &n);
    for(int j=0; j<n; j++){
      int tmph;
      scanf("%d", &tmph);
      h.push_back(tmph);
    }
    printf("%d\n", solve(0, n-1));
    // 사용한 h배열을 초기화 해야
    // 다음 입력에 대해 문제를 풀 때 오답이 발생하지 않음
    h.clear();
  }
}
