#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, result = 0;

  cin >> n;

  // n번 반복
  for(int i = 0; i < n; i++)
  {
    int plug;

    cin >> plug;

    if(i + 1 == n)
    {
      result += plug;
    }
    else 
      result += plug - 1;
  }

  cout << result << "\n";
}