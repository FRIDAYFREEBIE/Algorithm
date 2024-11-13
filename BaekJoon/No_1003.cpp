#include <iostream>

using namespace std;

pair<long, long> d[42]; // <0, 1>
int n, t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // 0: 1 0 1: 0 1
  d[0].first = 1;
  d[0].second = 0;
  d[1].first = 0;
  d[1].second = 1;

  for(int i = 2; i <= 40; i++){
    d[i].first = d[i - 1].first + d[i - 2].first;
    d[i].second = d[i - 1].second + d[i - 2].second;
  }

  cin >> t;

  while(t--){
    cin >> n;

    cout << d[n].first << " " << d[n].second << "\n";
  }

  return 0;
}