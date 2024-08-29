#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int fullPrice, price = 0;

  cin >> fullPrice;

  // 가격 합 구하기
  for(int i = 0; i < 9; i++)
  {
    int t;

    cin >> t;

    price += t;
  }

  cout << fullPrice - price << "\n";
}