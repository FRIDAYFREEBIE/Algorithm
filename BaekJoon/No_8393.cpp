#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, sum = 0;

  cin >> n;

  // n번 반복
  for(int i = 1; i <= n; i++)
  {
    sum += i;
  }

  cout << sum << "\n";
}