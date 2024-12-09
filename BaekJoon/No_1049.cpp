#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, x, y;
  cin >> n >> m;

  int single = 1000, set = 1000;

  while(m--){
    cin >> x >> y;

    set = min(set, x);
    single = min(single, y);
  }

  cout << min((n / 6 + 1) * set, min(n / 6 * set + n % 6 * single, n * single)) << "\n";

  return 0;
}