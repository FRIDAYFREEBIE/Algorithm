#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int max = 0, index = 0;

  for(int i = 0; i < 9; i++)
  {
    int t;

    cin >> t;

    if(t > max)
    {
      max = t;
      index = i;
    }
  }

  cout << max << "\n" << index + 1 << "\n";

  return 0;
}