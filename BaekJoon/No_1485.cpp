#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dist(pair<int, int> a, pair<int, int> b){
  return (a.first - b.first) * (a.first - b.first)  + (a.second - b.second) * (a.second - b.second);


}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;

  while(t--){
    vector<pair<int, int>> v;
    for(int i = 0; i < 4; i++){
      int x, y;
      cin >> x >> y;
      v.push_back({x, y});
    }

    sort(v.begin(), v.end());

    int a = dist(v[0], v[1]);
    int b = dist(v[0], v[2]);
    int c = dist(v[3], v[1]);
    int d = dist(v[3], v[2]);
    int e = dist(v[0], v[3]); 
    int f = dist(v[1], v[2]);

    if(a == b && b == c && c == d && e == f) cout << 1 << "\n";
    else cout << 0 << "\n";
  }

  return 0;
}