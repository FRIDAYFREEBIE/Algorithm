#include <iostream>
#include <climits>

using namespace std;

int arr[1001][3];
int cost[1001][3]; // r g b
int n, ans = 100000;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 1; i <= n; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

  // r g b 3번 반복
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(j == i) arr[1][j] = cost[1][j];
      else arr[1][j] = 100000;
    }

    // 두 번째 집 부터
    for(int j = 2; j <= n; j++){
      arr[j][0] = cost[j][0] + min(arr[j - 1][1], arr[j - 1][2]);
      arr[j][1] = cost[j][1] + min(arr[j - 1][0], arr[j - 1][2]);
      arr[j][2] = cost[j][2] + min(arr[j - 1][0], arr[j - 1][1]);
    }

    for(int j = 0; j < 3; j++){
      // 첫 번째 집과 마지막 집이 같은 경우는 제외
      if(i == j) continue;
      ans = min(ans, arr[n][j]);
    }
  }

  cout << ans << "\n";

  return 0;
}