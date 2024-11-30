#include <iostream>
#include <vector>

using namespace std;

// 소수를 연속합으로 나타낼 수 있는 경우의 수 구하기

// 1. 에라스토네스의 체를 사용하여 소수 배열을 생성 (1 ≤ N ≤ 4,000,000)
// 2. 소수 배열을 순회하며 경우의 수 카운트 

// 3: 3 -> 1
// 41: 2 + 3 + 5 + 7 + 11 + 13, 11 + 13 + 17, 41 -> 3
// 53: 5 + 7 + 11 + 13 + 17, 52 -> 2

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> primes; // 소수 배열
  vector<bool> isPrime(n + 1, true);

  isPrime[0] = isPrime[1] = false;
  for(int i = 2; i <= n; i++){
    if(isPrime[i]){
      primes.push_back(i);

      for(int j = i + i; j <= n; j = j + i) isPrime[j] = false;
    }
  }

  // 투 포인터
  int start = 0, end = 0, sum = 0, cnt = 0;
  while(end <= primes.size()){
    if(sum < n){
      if(end < primes.size()) sum += primes[end];

      end++;
    }
    else if(sum > n){
      sum -= primes[start];
      start++;
    }
    else if(sum == n){
      cnt++;

      if(end < primes.size()) sum += primes[end];

      end++;
    }
  }

  cout << cnt << "\n";

  return 0;
}