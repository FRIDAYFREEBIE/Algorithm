#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int a, b, divisor, multiple;

  cin >> a >> b;

  int i = 1;

  // 최대 공약수
  while (true)
  {
    // i가 a, b를 초과하면 break
    if(i > a || i > b)
      break;

    // a, b가 i로 나뉘어진다면 공약수 갱신
    if(a % i == 0 && b % i == 0)
      divisor = i;

    i++;
  }

  int ta = a, tb = b;

  // 최소 공배수
  while(true)
  {
    // ta가 b 보다 작다면 a만큼 증가
    if(ta < tb)
      ta += a;
    // tb가 a 보다 작다면 b만큼 증가
    else if(tb < ta)
      tb += b;

    // a와 b가 같다면 최소공배수
    if(ta == tb)
    {
      multiple = ta;
      break;
    }
  }

  cout << divisor << "\n";
  cout << multiple << "\n";
}