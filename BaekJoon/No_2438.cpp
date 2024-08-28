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
    // i번 반복
    for(int  j = 0; j < i; j++)
    {
      cout << "*";
    }

    cout << "\n";
  }
}