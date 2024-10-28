#include <iostream>
#include <vector>

using namespace std;

// a^b를 계산하는 함수
int power(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b;
  cin >> a >> b;

  int m;
  cin >> m;

  vector<int> baseVector(m);
  for (int i = 0; i < m; i++) {
    cin >> baseVector[i];
  }

  // a -> 10
  long long num = 0;
  for (int i = 0; i < m; i++) {
    num += baseVector[i] * power(a, m - 1 - i);
  }


  if (num == 0) {
    cout << 0 << "\n";
    return 0;
  }

  // 10 -> b
  vector<int> bVector;
  while (num != 0) {
    int remain = num % b;
    num /= b;
    bVector.push_back(remain);
  }

  for (int i = bVector.size() - 1; i >= 0; i--) {
    cout << bVector[i] << " ";
  }
  cout << "\n";

  return 0;
}

int power(int a, int b) {
  int result = 1;
  for (int i = 0; i < b; i++) {
    result *= a;
  }
  return result;
}