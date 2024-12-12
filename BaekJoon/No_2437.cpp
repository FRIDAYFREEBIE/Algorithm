#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
  v.resize(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  sort(v.begin(), v.end());

  int sum = 0;
  for(int value : v){
    if(value > sum + 1) break;

    sum += value;
  }

  cout << sum + 1 << "\n";

  return 0;
}