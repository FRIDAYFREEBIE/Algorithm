#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int result = -1;

  for (int i = n / 5; i >= 0; i--) {
    int temp = n - (i * 5);
    if (temp % 3 == 0) {
      result = i + (temp / 3);
      break;
    }
  }

  cout << result << "\n";

  return 0;
}
