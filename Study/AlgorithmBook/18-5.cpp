// 18.5 문제 : 조세푸스 문제
#include <cstdio>
#include <list>
#include <iostream>
using namespace std;
void josephus(int n, int k){
  // 리스트 준비
  list<int> survivors;
  for(int i=1; i<=n; i++){
    survivors.push_back(i);
  }
  // 이번에 사라질 사람을 나타내는 포인터
  list<int>::iterator kill = survivors.begin();
  while(n>2){
    // 첫 번째 사람이 사라짐. erase()는 지운 원소의 다음 원소 반환
    kill = survivors.erase(kill);
    if(kill==survivors.end()) kill = survivors.begin();
    n--;
    // k-1번 다음 사람으로 옮기기
    for(int i=0; i<k-1; i++){
      kill++;
      if(kill==survivors.end()) kill = survivors.begin();
    }
  }
  cout << survivors.front() << " " << survivors.back() << "\n";
}

int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    int n, k;
    scanf("%d %d", &n, &k);
    josephus(n, k);
  }
}
