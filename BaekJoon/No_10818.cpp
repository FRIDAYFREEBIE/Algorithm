#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, min = 1000001, max = -1000001;

  cin >> n;

  for(int i = 0; i < n; i++)
  {
    int temp;

    cin >> temp;

    if(temp < min)
      min = temp;
    if(temp > max)
      max = temp;
  }

  cout << min << " " << max << "\n";

  return 0;
}