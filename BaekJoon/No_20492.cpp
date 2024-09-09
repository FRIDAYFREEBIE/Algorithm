#include <iostream>
#include <string>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  cin >> n;

  cout << n * 78 / 100 << ' ' << n * 8 / 10 + (n * 2 / 10) * 78 / 100 << "\n";

  return 0;
}