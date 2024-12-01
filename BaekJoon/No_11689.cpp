#include <iostream>
#include <cmath>

using namespace std;

// 오일러 피 구현하기
// p[n]은 1 ~ n 까지 서로소인 자연수의 갯수
// 1. 배열 초기화
// 2. 2부터 순회
// 2-1. (value == index) -> 현재 선택된 숫자의 배수에 해당하는 수를 배열의 끝까지 탐색(p[i] - (p[i] / 2))

// ex)
// 1 2 3 4 5
// 1 1 3 2 5

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long n;
  cin >> n;

  long long result = n;
  for(long long i = 2; i <= sqrt(n); i++){
    // 소인수 일 때
    if(n % i == 0){
      result = result - result / i;

      // 소인수 지우기
      while(n % i == 0) n /= i;
    }
  }

  // 소인수 구성이 남아있을 때
  if(n > 1) result = result - result / n;

  cout << result << "\n";

  return 0;
}