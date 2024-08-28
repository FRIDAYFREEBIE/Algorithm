#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int  n;

  cin >> n;

  // n번 반복
  for(int i = 1; i <= 9; i++)
  {
    cout << n << " * " << i << " = " << n * i << "\n";
  }
}