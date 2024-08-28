#include <iostream>
#include <string>

using namespace std;

int main()
{
  ios :: sync_with_stdio(false);

  int n, i = 0, playerPrice = 0;
  string playerName[100];

  cin >> n;

  int p;

  // 비싼 선수 탐색
  for(i; i < n; i++)
  {
    cin >> p;

    playerPrice = 0;

    int tempPrice;
    string tempName;

    for(int j = 0; j < p; j++)
    {
      cin >> tempPrice >> tempName;

      if(playerPrice < tempPrice)
      {
        playerPrice = tempPrice;
        playerName[i] = tempName;
      }
    }
  }

  // 출력
  for(int k = 0; k <= i; k++)
  {
    cout << playerName[k] << "\n";
  }
}