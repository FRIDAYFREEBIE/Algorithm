#include <iostream>
#include <algorithm>

using namespace std;

int n, k, arr[1000001];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;

  for(int i = 0; i < n; i++) cin >> arr[i];

  // 초기 구간
  int sum = 0, maxSum = 0;
  for(int i = 0; i < k; i++) sum += arr[i];

  maxSum = sum;

  for(int i = k; i < n; i++){
    sum += arr[i] - arr[i - k];
    maxSum = max(maxSum, sum);
  }

  cout << maxSum << "\n";

  return 0;
}