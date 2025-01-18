#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
vector<int> v, cost;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> k;
  v.resize(n);
  cost.resize(n - 1);

  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  // for(auto a : v) cout << a << "\n";

  for(int i = 1; i < n; i++) cost[i - 1] = v[i] - v[i - 1];

  sort(cost.begin(), cost.end());

  long long ans = 0;
  for(int i = 0; i < n - k; i++) ans += cost[i];

  cout << ans << "\n";

  return 0;
}