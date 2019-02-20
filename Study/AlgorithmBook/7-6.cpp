#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
// 자리수 처리 생략으로 normalize() 생략
vector<int> multiply(const vector<int>& a, const vector<int>& b){
  vector<int> c(a.size()+b.size()+1, 0);
  for(int i=0; i<a.size(); i++){
    for(int j=0; j<b.size(); j++){
      c[i+j] += a[i]*b[j];
    }
  }
  return c;
}
// a+=b (자리수 처리 생략으로 원래 코드 변형)
void addTo(vector<int>& a, const vector<int>& b, int k){
  for(int i=0; i<b.size(); i++){
    a[i]+=b[i];
  }
}
// a-=b (a>=b)
void subFrom(vector<int>&a, const vector<int>& b){
  // a에서 b 뺴기 (각 자리수)
  for(int i=b.size(); i>=0; i--){
    a[i]-=b[i];
  }
}
// 두 긴 정수의 곱 반환 (이 때, 자리수 처리는 하지 않음)
vector<int> karatsuba(const vector<int>&a, const vector<int>& b){
  int an = a.size(), bn = b.size();
  // a가 b보다 짧을 경우 둘을 바꾼다
  if(an<bn) return karatsuba(b, a);
  // 기저사례 : a 또는 b가 비어 있는 경우
  if(an==0 || bn==0) return vector<int>();
  // 기저사례 : a가 짧은 경우 O(n^2) 곱셈으로 변경
  if(an <= 50) return multiply(a,b);
  // 자릿수를 나눌 기준
  int half = an/2;
  // a와 b를 밑에서 half자리와 나머지로 분리
  vector<int> a0(a.begin(), a.begin()+half);
  vector<int> a1(a.begin()+half, a.end());
  // b의 길이가 a의 길이의 절반보다 짧을 경우를 대비
  vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
  vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());
  // z2 = a1*b1
  vector<int> z2 = karatsuba(a1, b1);
  // z0 = a0*b0
  vector<int> z0 = karatsuba(a0, b0);
  // a0 = a0+a1 ; b0 = b0+b1;
  addTo(a0, a1, 0); addTo(b0, b1, 0);
  // z1 = (a0*b0)-z0-z2 (바뀐 a0와 b0 기준)
  vector<int> z1 = karatsuba(a0, b0);
  subFrom(z1, z0); subFrom(z1, z2);
  // 자리수 처리 없이 그냥 더함
  vector<int> ret;
  addTo(ret, z0, 0); addTo(ret, z1, 0); addTo(ret, z2, 0);
  return ret;
}

int hugs(const string& members, const string& fans){
  int N = members.size(), M = fans.size();
  vector<int> A(N), B(M);
  // 남성이면 1, 여성이면 0으로 저장
  for(int i=0; i<N; i++){
    A[i] = (members[i]=='M');
  }
  for(int i=0; i<M; i++){
    B[M-i-1] = (fans[i]=='M');
  }
  // karatsuba 알고리즘에서 자리 올림은 생략
  vector<int>C = karatsuba(A,B);
  int allHugs = 0;
  for(int i = N-1; i < M; i++){
    if(C[i]==0){
      allHugs++;
    }
  }
  return allHugs;
}

int main(){
  int c;
  scanf("%d\n", &c);
  for(int i=0; i<c; i++){
    string m; string f;
    cin >> m;
    cin >> f;
    cout << hugs(m, f) << "\n";
  }
}
