#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n, k;

  cin >> n >> k;

  int a = 1;

  for(int i = n - k + 1; i <= n; i++){
    a *= i;
  }

  int b = 1;

  for(int i = 1; i <= k; i++){
    b *= i;
  }

  cout << a/b << "\n";

  return 0;
}