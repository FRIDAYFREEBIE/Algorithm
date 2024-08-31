#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int a, b, c, t;

  cin >> a >> b >> c;

  cout << a + b - c << "\n";

  if(b < 10)
    t = 10 * a + b - c;
  else if(b < 100)
    t = 100 * a + b - c;
  else if(b < 1000)
    t = 1000 * a + b - c;
  else
    t = 10000 * a + b - c;

  cout << t << "\n";

  return 0;
}