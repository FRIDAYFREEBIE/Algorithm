#include <iostream>

using namespace std;

int n;
int num[100001]; // 수 배열
int dp[100001]; // 연속합 DP 배열

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++){
    cin >> num[i];
  }

  dp[0] = num[0];

  int ans = dp[0];
  for(int i = 1; i < n; i++){
    if(dp[i - 1] > 0) dp[i] = dp[i - 1] + num[i];
    else dp[i] = num[i];

    if(dp[i] > ans) ans = dp[i];
  }

  cout << ans << "\n";

  return 0;
}