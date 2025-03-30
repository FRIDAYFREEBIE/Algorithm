#include <iostream>

using namespace std;

int n, ans;
int arr[1001];
int DP[1001];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  for(int i = 0; i < n; i++) DP[i] = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
      if(arr[i] > arr[j]) DP[i] = max(DP[i], DP[j] + 1);
    }

    ans = max(DP[i], ans);
  }

  cout << ans << "\n";

  return 0;
}