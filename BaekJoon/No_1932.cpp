#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501];
int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++){
    for(int j = 0; j <= i; j++){
      cin >> arr[i][j];
    }
  }

  int result = arr[0][0];

  for(int i = 1; i <= n; i++){
    for(int j = 0; j <= i; j++){
      if(i == j) arr[i][j] = arr[i][j] + arr[i - 1][j - 1];
      else if(j == 0) arr[i][j] = arr[i][j] + arr[i - 1][j];
      else arr[i][j] = arr[i][j] + max(arr[i - 1][j - 1], arr[i - 1][j]);

      if(i == n - 1) result = max(result, arr[i][j]);
    }
  }

  cout << result << "\n";

  return 0;
}