#include <iostream>

using namespace std;

int n, ans;
int arr[1001];
int DP[1001]; // DP[i]는 i에서 가장 긴 감소 수열의 길이

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  // DP 배열 초기화 가장 짧은 길이는 1
  for(int i = 0; i < n; i++) DP[i] = 1;

  // 감소 수열은 수열을 역순으로 탐색한 증가 수열과 같다
  for(int i = n - 1; i >= 0; i--){
    for(int j = n - 1; j > i; j--){
      if(arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + 1);
    }

    ans = max(ans, DP[i]);
  }

  cout << ans << "\n";

  return 0;
}