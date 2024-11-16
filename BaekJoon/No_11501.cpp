#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    long long money = 0;
    int price = 0;

    for(int i = n - 1; i >= 0; i--){
      if (v[i] > price) price = v[i];
      else money += price - v[i];
    }

    cout << money << "\n";
  }

  return 0;
}
