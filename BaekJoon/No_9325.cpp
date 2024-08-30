#include <iostream>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int  n;

  cin >> n;

  // n번 반복
  for(int i = 0; i < n; i++)
  {
    int price = 0, option;

    cin >> price;
    cin >> option;

    // option개의 옵션 가격 계산
    for(int j = 0; j < option; j++)
    {
      int optionCount, optionPrice, temp = 0;

      cin >> optionCount >> optionPrice;

      temp += optionCount * optionPrice;

      price += temp;
    }

    cout << price << "\n";
  }
}