#include <iostream>
#include <algorithm>

using namespace std;

int n;
int rope[100000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> rope[i];
  }

  sort(rope, rope + n);

  int result = 0;
  for(int i = 1; i <= n; i++){
    result = max(result, rope[n - i] * i);
  }

  cout << result << "\n";

  return 0;
}