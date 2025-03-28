#include <iostream>

using namespace std;

int n, ans;
int arr[16][3]; // [i][0] = 시간 [i][1] = 비용
int DP[16];  // DP

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

  for(int i = n; i >= 1; i--){
    // 최대 수익 갱신
    DP[i] = max(DP[i], DP[i + 1]);

    // 가능한 업무인지 확인
    if(i + arr[i][0] <= n + 1) DP[i] = max(DP[i], arr[i][1] + DP[i + arr[i][0]]);
  }

  cout << DP[ 1] << "\n";

  return 0;
}