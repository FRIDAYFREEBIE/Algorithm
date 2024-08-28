#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // n번 반복
  for(int i = 0; i < n; i++)
  {
    cout << i + 1 << "\n";
  }
}