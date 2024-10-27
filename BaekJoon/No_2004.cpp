#include <iostream>

using namespace std;

long long count(long long n, int a);

// n! / m!(n - m)!
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long n, m;
  cin >> n >> m;

  long long fiveCount = count(n, 5) - count(m, 5) - count(n - m, 5);
  long long twoCount = count(n, 2) - count(m, 2) - count(n - m, 2);

  if(fiveCount > twoCount){
    cout << twoCount << "\n";
  }
  else if(fiveCount < twoCount){
    cout << fiveCount<< "\n";
  }
  else{
    cout << fiveCount << "\n";
  }

  return 0;
}

long long count(long long n, int a){
  long long count = 0;
  // 1: 5의 배수
  // 2~: 5의 거듭제곱
  for (long long i = a; i <= n; i *= a){
    count += n / i;
  }

  return count;
}