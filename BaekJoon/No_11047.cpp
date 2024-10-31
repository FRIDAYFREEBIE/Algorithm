#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  vector<int> coinVector(n); // 동전 벡터
  for(int i = 0; i < n; i++){
    cin >> coinVector[i];
  }

  int remain = k, result = 0;
  for(int i = n - 1; i >= 0; i--){
    result += remain / coinVector[i];
    remain %= coinVector[i];
  }

  cout << result << "\n";

  return 0;
}