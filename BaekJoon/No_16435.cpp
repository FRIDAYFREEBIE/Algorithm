#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, l;
  cin >> n >> l;

  vector<int> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  for(int i = 0; i < n; i++){
    if(v[i] <= l) l++;
  }

  cout << l << "\n";

  return 0;
}