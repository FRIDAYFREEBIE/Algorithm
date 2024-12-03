#include <iostream>

using namespace std;

// 문제 정리
// 주어진 두 수의 최대 공약수는 A, B의 최대 공갹수의 길이를 나타냄
// EX) 3, 6 -> 111과 111111의 최대 공약수 111(3)

// 문제 풀이
// 1. 유클리드 호제법을 사용하여 주어진 두 수의 최대 공약수를 구함
// 2. 공약수의 길이만큼 1을 출력


// 유클리드 호제법 재귀 함수
long long func(long long a, long long b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long a, b;
  cin >> a >> b;

  long long result = func(a, b);

  while(result--) cout << 1;

  cout << "\n";

  return 0;
}

// 유클리드 호제법 재귀 함수
long long func(long long a, long long b){
  // b가 0이면 최대 공약수는 a
  if(b == 0) return a;
  else return func(b, a % b);
}

