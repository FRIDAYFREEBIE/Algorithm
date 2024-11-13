#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for (int i = 2; i <= n; i++) {
    arr[i] = arr[i - 1] + 1;

    if (i % 3 == 0) {
      arr[i] = min(arr[i], arr[i / 3] + 1);
    }
    if (i % 2 == 0) {
      arr[i] = min(arr[i], arr[i / 2] + 1);
    }
  }

  cout << arr[n] << "\n";

  return 0;
}