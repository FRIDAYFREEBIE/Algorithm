#include <iostream>

using namespace std;

pair<int, int> p1, p2, p3, p4;

int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c){
  return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

  

  return 0;
}