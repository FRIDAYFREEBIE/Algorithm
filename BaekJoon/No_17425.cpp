#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int max = 1000000;

  vector<long long> v1(max + 1, 0);

  for (int i = 1; i <= max; i++) {
    for (int j = i; j <= max; j += i) {
      v1[j] += i;
    }
  }

  vector<long long> v2(max + 1, 0);

  for (int i = 1; i <= max; i++) {
    v2[i] = v2[i - 1] + v1[i];
  }

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << v2[n] << "\n";
  }

  return 0;
}
