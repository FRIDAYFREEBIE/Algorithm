#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> prime();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  vector<int> numVector(t);
  for (int i = 0; i < t; i++) {
    cin >> numVector[i];
  }

  vector<int> primeVector = prime();  // 소수 벡터

  for (int i = 0; i < t; i++) {
    int n = numVector[i];
    int partitionCnt = 0;  // 파티션 갯수

    // 중복 방지 n / 2
    for (int j = 0; primeVector[j] <= n / 2; j++) {
      int prime1 = primeVector[j];
      int prime2 = n - prime1;

      // prime2가 소수라면
      if (binary_search(primeVector.begin(), primeVector.end(), prime2)) {
        partitionCnt++;
      }
    }

    cout << partitionCnt << "\n";
  }

  return 0;
}

vector<int> prime() {
  int n = 1000000;
  vector<bool> isPrime(n + 1, true);

  // 0, 1은 소수가 아님
  isPrime[0] = false;
  isPrime[1] = false;

  // 배수 제거
  for (int i = 2; i * i <= n; i++) {
    if (isPrime[i]) {
      for (int j = i * i; j <= n; j += i) {
        isPrime[j] = false;
      }
    }
  }

  // 소수 벡터
  vector<int> primes;
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}
