#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, reward = 0;

  cin >> n;

  // 나머지 합산 n번 반복
  for(int i = 0; i < n; i++)
  {
    int a, b;

    cin >> a >> b;

    reward += b % a;
  }

  cout << reward << "\n";
}