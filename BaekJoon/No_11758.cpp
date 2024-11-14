#include <iostream>

using namespace std;

pair<int, int> p1, p2, p3;

int CCW(){
  return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second;

  int result = CCW();

  if(result > 0) cout << 1 << "\n";
  else if(result < 0) cout << -1 << "\n";
  else cout << 0 << "\n";

  return 0;
}