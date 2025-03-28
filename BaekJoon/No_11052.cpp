#include <iostream>

using namespace std;

int n;
int card[1001]; // 카드 배열
int DP[1001];   // 카드 가격 DP 배열

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 1; i <= n; i++)
    cin >> card[i];


  // 카드 N개를 살 때의 최댓값 => max(dp[i], dp[i - j] + card[j])
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= i; j++)
      DP[i] = max(DP[i], DP[i - j] + card[j]);
  }
  
  // for(int i = 1; i <= n; i++){
  //   cout << DP[i] << " ";
  // }

  // cout << "\n";
  
  cout << DP[n] << "\n";

  return 0;
}