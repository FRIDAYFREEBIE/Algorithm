#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  int k;
  cin >> k;

  vector<int> s(n);
  for(int i = 0; i < n; i++) cin >> s[i];

  sort(s.begin(), s.end());

  // 1 6 9 3 6 7
  // 1 3 6 6 7 9
  // -> 1 ~ 3(2) + 6 ~ 9(3) 5

  vector<int> v(n - 1);
  for(int i = 0; i < n - 1; i++) v[i] = s[i + 1] - s[i];

  sort(v.begin(), v.end(), greater<>());

  int answer = 0;
  for(int i = k - 1; i < n; i++) answer += v[i];

  cout << answer << "\n";

  return 0;
}