#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num, a, n, cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++) cin >> v[i];

  for(int i = n - 1; i > 0; i--){
    if(v[i] > v[i - 1]) continue;

    num = v[i - 1] - v[i] + 1;
    v[i - 1] -= num;
    cnt += num;
  }

  cout << cnt << "\n";

  return 0;
}