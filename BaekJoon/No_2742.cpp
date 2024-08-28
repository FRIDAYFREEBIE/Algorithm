#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // n번 반복
  for(int i = n; i > 0; i--)
  {
    cout << i << "\n";
  }
}