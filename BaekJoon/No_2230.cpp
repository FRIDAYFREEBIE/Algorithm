#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  v.resize(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  // 투 포인터
  int end = 0, ans = INT_MAX;
  for(int start = 0; start < n; start++){
    // end가 범위 내, m보다 큰 최초의 값
    while(end < n && v[end] - v[start] < m) end++;

    if(end == n) break;

    ans = min(ans, v[end] - v[start]);
  }

  cout << ans << "\n";

  return 0;
}