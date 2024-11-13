#include <iostream>

using namespace std;

int d[1001];
int n, mod = 10007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  d[1] = 1;
  d[2] = 2;

  for(int i = 3; i <= n; i++){
    d[i] = (d[i - 1] + d[i - 2]) % mod;
  }

  cout << d[n] << "\n";

  return 0;
}