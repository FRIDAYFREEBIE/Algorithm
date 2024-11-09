#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  long long int n, a = 0, b = 1, c;

  cin >> n;

    
  if(n == 0)
    c = 0;
  else if(n == 1)
    c = 1;
  else
  {
    // n 번째의 피보나치 수 구하기
    for(int i = 1; i < n; i++)
    {
      c = a + b;

      a = b;
      b = c;
    }
  }
  
  cout << c << "\n";
}