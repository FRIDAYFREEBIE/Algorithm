#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  if (n == 1) cout << 1;
  else if (n == 2) cout << min(4, (m + 1) / 2);
  else if (m < 7) cout << min(4, m);
  else cout << m - 2;

  return 0;
}