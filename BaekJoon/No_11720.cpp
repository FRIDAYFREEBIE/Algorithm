#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, result = 0;
  char c;

  cin >> n;

  for(int i = 0; i < n; i++)
  {
    cin >> c;

    result += c - 48; // 아스키 코드
  }

  cout << result << "\n";

  return 0;
}