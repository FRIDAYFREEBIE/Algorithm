#include <iostream>
#include <cmath>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  unsigned int n;
  cin >> n;

  unsigned int windowCnt = 0;
  for (unsigned int i = 1; i * i <= n; i++) {
    windowCnt++;
  }

  cout << windowCnt << "\n";

  return 0;
}
