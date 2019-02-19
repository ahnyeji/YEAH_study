#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
string reverse(string::iterator& it){
  char head = *it;
  // 반복자가 다음 글자를 가리키게 함
  it++;
  // 지금 검사하고 있는 글자가 b또는 w
  if(head=='b' || head=='w'){
    // 1글자 문자열을 반환
    // string(size_t, char c)
    // 는 c를 t만큼 채워서 반환하는 함수
    return string(1,head);
  }
  // 검사한 글자가 x
  // 함수가 호출될 때 마다 반복자는 1씩 커진 상태
  // 왼쪽 위의 쿼드트리 압축부분 (입력된 반복자+1 된 상태)
  string upperLeft = reverse(it);
  // 오른쪽 위의 쿼드트리 압축부분 (왼쪽 위를 가리키는 반복자+1 된 상태)
  string upperRight = reverse(it);
  // 왼쪽 아래의 쿼드트리 압축부분 (오른쪽 위를 가리키는 반복자+1 된 상태)
  string lowerLeft = reverse(it);
  // 오른쪽 아래의 쿼드트리 압축부분 (왼쪽 아래를 가리키는 반복자+1 된 상태)
  string lowerRight = reverse(it);
  // 위아래 뒤집기 : 왼쪽, 오른쪽의 순서는 바뀌지 않은 상태로 위, 아래만 바뀜
  // 위에서 한글자 짜리는 처리했기 때문에 x가 표시되어야 함
  return string("x")+lowerLeft+lowerRight+upperLeft+upperRight;
}

int main(){
  int c;
  scanf("%d", &c);
  for(int i=0; i<c; i++){
    string ip;
    cin >> ip;
    string::iterator iter = ip.begin();
    string ans = reverse(iter);
    cout<< ans<<'\n';
  }
}
