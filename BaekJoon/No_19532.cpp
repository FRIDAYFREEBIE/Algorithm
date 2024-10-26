#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int y = (c * d - a * f) / (b * d - a * e);
	int x = (c * e - b * f) / (a * e - b * d);

  cout << x << " " << y << "\n";

  return 0;
}