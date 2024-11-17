#include <iostream>

using namespace std;

int n, k, w[101], v[101], dp[101][100001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= k; j++){
      int weight = w[i];
      int value = v[i];

      // 무거워서 못 넣음
      if(weight > j) dp[i][j] = dp[i - 1][j];
      // 넣을 수 있음
      else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value); // i를 포함했을 때 얻을 수 있는 최대 가치
    }
  }

  cout << dp[n][k] << "\n";

  return 0;
}