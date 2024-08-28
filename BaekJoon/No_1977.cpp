#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int m, n, sum = 0, min =0, temp;

  cin >> m;
  cin >> n;

  for(int i=1; i*i<=n; i++)
  {
    temp = i*i; // 완전제곱수

    if(temp >= m)
    {
      sum += temp; // 합
      if(min == 0) // 최소
        min = temp;
    }
  }

  if(sum == 0) // 완전제곱수 X
    cout << -1 << "\n";
  else
  {
    cout << sum << "\n";
    cout << min << "\n";
  }
}