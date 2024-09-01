#include <iostream>

using namespace std;

// 모듈러 연산
// x mod n = (x mod n) mod n
// temp %= n으로 크기를 줄이고 if(temp % n == 0)을 해도 결과는 같다
int main()
{
  ios :: sync_with_stdio(false);

  int n, temp, i;

  while(cin >> n)
  {
    i = 1;
    temp = 1;

    while (true)
    {
      if(temp % n == 0) // 모듈러 연산
        break;
      
      temp = 10 * temp + 1;
      temp %= n; // 모듈러 연산
      i ++;
    }

    cout << i << "\n";
  }

  return 0;
}