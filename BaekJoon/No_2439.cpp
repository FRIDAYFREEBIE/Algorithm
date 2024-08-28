#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // n번 반복
  for(int i = 1; i <= n; i++)
  {
    // n - i 번 반복 (공백)
    for(int j = 0; j < n - i; j++)
    {
      cout << " ";
    }

    // i 번 반복 (*)
    for(int k = 0; k < i; k++)
    {
      cout << "*";
    }

    cout << "\n";
  }
}