#include <iostream>
#include <vector>

using namespace std;

vector<int> prime();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> primeVector = prime();

  while(true){
    int n;
    cin >> n;

    if(n == 0){
      break;
    }

    int primeCnt = 0;
    for(int a : primeVector){
      if(n < a && n * 2 >= a){
        primeCnt++;
      }
    }

    cout << primeCnt << "\n";
  }

  return 0;
}

vector<int> prime(){
  int n = 123456 * 2;
  vector<bool> isPrime(n + 1, true);

  // 0, 1은 소수가 아님
  isPrime[0] = false;
  isPrime[1] = false;

  //배수 제거
  for (int i = 2; i * i <= n; i++){
    if (isPrime[i]){
      for (int j = i * i; j <= n; j += i){
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes; // 소수 벡터
  for (int i = 2; i <= n; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  return primes;
}