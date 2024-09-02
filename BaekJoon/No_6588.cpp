#include <iostream>
#include <cstring>

using namespace std;

void Prime(); // 에라토스테네스의 체

bool isPrime[1000001]; // 소수 배열

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  Prime(); // 소수 계산

  while (true) {
    cin >> n;

    if (n == 0) break;

    bool isFound = false;
    int prime1 = 0, prime2 = 0; // 가장 작은 a 가장 큰 b

    for (int i = 3; i <= n / 2; i += 2) { // 홀수 소수만 탐색
      int b = n - i;
      if (isPrime[i] && isPrime[b] && b % 2 == 1) {
        prime1 = i;
        prime2 = b;
        isFound = true;
        break;
      }
    }

    if (isFound) cout << n << " = " << prime1 << " + " << prime2 << "\n";
    else cout << "Goldbach's conjecture is wrong." << "\n";
  }

  return 0;
}

void Prime() {
  memset(isPrime, true, sizeof(isPrime)); // 배열 초기화

  isPrime[0] = isPrime[1] = false; // 0과 1은 소수 X
  isPrime[2] = true; // 2는 짝수 소수

  for (int i = 3; i * i <= 1000000; i += 2){ // 에라토스테네스의 체
    if (isPrime[i]) {
      for (int j = i * i; j <= 1000000; j += i * 2){ // 홀수만 계산
        isPrime[j] = false; // i의 배수는 소수가 아님
      }
    }
  }
}
