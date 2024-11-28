#include <iostream>
#include <cmath>

using namespace std;

// 거의 소수: 어떤 수가 소수의 N제곱일 때
// a와 b사이의 거의 소수 갯수를 카운트

// 1. 에라스토네스의 체를 사용하여 소수를 구하기
// 2. 주어진 소수가 a ~ b안에 존재하는지 판별(카운트)


// 범위가 10^14이므로 10^14의 제곱근인 10^7까지 탐색

long long a, b, arr[10000001], cnt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  // 소수 배열 초기화
  for(int i = 2; i < 10000001; i++) arr[i] = i;

  // 에라스토네스의 체(제곱근 까지)
  for(int i = 2; i <= sqrt(10000001); i++){
    if(arr[i] == 0) continue;

    // 배수 지우기
    for(int j = i + i; j < 10000001; j = j + i) arr[j] = 0;
  }

  // 거의 소수 카운트
  for(int i = 2; i < 10000001; i++){
    if(arr[i] != 0){
      long long temp = arr[i];

      // 소수의 N제곱이 B보다 커질 때 까지
      while((double)arr[i] <= (double)b / (double)temp){
        // 소수의 N제곱이 A보다 크거나 같으면 카운트
        if((double)arr[i] >= (double)a / (double)temp) cnt++;

        // 소수 N제곱
        temp = temp * arr[i];
      }
    }
  }

  cout << cnt << "\n";

  return 0;
}