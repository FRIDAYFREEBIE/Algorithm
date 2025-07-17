#include <iostream>

using namespace std;

int n, ans;
int arr[1001];  // 수열
int DP[1001];   // DP[i]는 i길이에서 가장 큰 감소 수열의 합

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  // 1. 현재 값(arr[i])보다 작은 수들로 이루어진 부분 수열 탐색
  // 2. 탐색한 부분 수열에 arr[i]도 포함
  for(int i = 0; i < n; i++){
    DP[i] = arr[i];

    for(int j = 0; j < i; j++){
      if(arr[i] < arr[j]) DP[i] = max(DP[i], DP[j] + arr[i]);
    }

    ans = max(ans, DP[i]);
  }

  cout << ans << "\n";
  

  return 0;
}