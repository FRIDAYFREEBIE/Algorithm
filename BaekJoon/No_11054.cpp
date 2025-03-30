#include <iostream>

using namespace std;

int n, ans;
int arr[1001];  // 수열
int increase[1001];   // 가장 긴 증가하는 부분 수열
int decrease[1001];   // 가장 긴 감소하는 부분 수열

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> arr[i];

  for(int i = 0; i < n; i++){
    increase[i] = 1;
    decrease[i] = 1;
  }

  for(int i = 0; i < n; i++){
    // arr[i]를 기준으로 가장 긴 증가하는 부분 수열 (왼쪽)
    for(int j = 0; j < i; j++){
      if(arr[i] > arr[j]) increase[i] = max(increase[i], increase[j] + 1);
    }
  }

  for(int i = n - 1; i >= 0; i--){
    // arr[i]를 기준으로 가장 긴 감소하는 부분 수열 (오른쪽)
    for(int j = n - 1; j > i; j--){
      if(arr[i] > arr[j]) decrease[i] = max(decrease[i], decrease[j] + 1);
    }
  }

  for(int i = 0; i < n; i++) ans = max(ans, increase[i] + decrease[i] - 1);


  cout << ans << "\n";

  return 0;
}