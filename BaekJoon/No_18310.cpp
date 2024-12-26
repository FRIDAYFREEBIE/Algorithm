#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int ans = n % 2 == 0 ? n / 2 - 1 : n / 2;
  cout << v[ans] << "\n";
  
  return 0;
}