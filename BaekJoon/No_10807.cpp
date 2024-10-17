#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, v, count = 0;
  cin >> n;

  vector<int> numbers(n);

  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  cin >> v;

  for (int i = 0; i < n; i++) {
    if (numbers[i] == v) {
      count++;
    }
  }

  cout << count << "\n";

  return 0;
}
