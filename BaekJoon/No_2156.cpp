#include <iostream>

using namespace std;

int n;
int arr[10001]; // 포도주 배열
int dp[10010];  // 연속합 DP 배열

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  dp[0] = arr[0];
  dp[1] = arr[0] + arr[1];
  dp[2] = max(max(dp[1] ,arr[1] + arr[2]),arr[2] + arr[0] );

  int current = 1;  // 연속한 포도주 카운트
  for(int i = 3; i < n; i++){
    dp[i] = max(max(dp[i - 1],dp[i - 3] + arr[i - 1] + arr[i]),dp[i - 2] + arr[i] );
  }

  cout << dp[n - 1] << "\n";

  return 0;
}