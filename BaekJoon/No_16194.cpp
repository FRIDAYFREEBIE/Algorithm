#include <iostream>
#include <climits>

using namespace std;

int n;
int card[1001]; // 카드 배열
int DP[1001];   // DP 배열

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 1; i <= n; i++) cin >> card[i];

  // 최소 비용으로 카드를 구매
  // DP[i] = DP[i - 1] + card[i]
  for(int i = 1; i <= n; i++){
    int temp = INT_MAX;
    for(int j = 1; j <= i; j++) temp = min(temp, DP[i - j] + card[j]);
    DP[i] = temp;
  }

  cout << DP[n] << "\n";

  // for(int i = 1; i <= n; i++){
  //   cout << DP[i] << " ";
  // }

  return 0;
}