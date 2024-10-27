#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long GCD(long long a, long long b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  long long n, s;
  cin >> n >> s;

  vector<long long> positionVector(n); // 위치 벡터
  vector<long long> minusVector(n); // 언니 위치 - 동생 위치 절댓값 벡터
  for(int i = 0; i < n; i++){
    cin >> positionVector[i];
    minusVector[i] = abs(s - positionVector[i]);
  }

  long long result = minusVector[0];
  for(int i = 1; i <n; i++){
    result = GCD(result, minusVector[i]);
  }

  cout << result << "\n";

  return 0;
}

long long GCD(long long a, long long b){
  if(b == 0){
    return a;
  }
  else{
    return GCD(b, a % b);
  }
}