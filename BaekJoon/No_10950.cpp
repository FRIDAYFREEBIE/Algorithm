#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n;

  cin >> n;

  // n번 연산
  for(int i = 0; i < n; i++)
  {
    int a, b;

    cin >> a >> b;

    cout << a + b;
  }
}