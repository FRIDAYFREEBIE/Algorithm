#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  cout << fixed;
	cout.precision(9);

  double a, b;

  cin >> a >> b;

  cout << a / b;
}