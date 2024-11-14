#include <iostream>

using namespace std;

long long arr[1001];
int n, mod = 10007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  arr[1] = 1;
  arr[2] = 3;

  for(int i = 3; i <= n; i++){
    arr[i] = (arr[i - 1] + (arr[i - 2] * 2)) % mod;
  }

  cout << arr[n] << "\n";

  return 0;
}