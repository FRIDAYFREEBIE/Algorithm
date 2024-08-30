#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int a, b, c, d, e;

  cin >> a >> b >> c >> d >> e;

  int temp = (a * a) + (b * b) + (c * c) + (d * d) + (e * e);

  cout << temp % 10 << "\n";
}