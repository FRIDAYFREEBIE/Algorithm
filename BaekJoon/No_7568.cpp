#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getRank(vector<pair<int, int>> v, int n);

int main() {
  ios :: sync_with_stdio(false);
  cin.tie(0);

  int n;

  cin >> n;

  vector<pair<int, int>> v;

  for(int i = 0; i < n; i++){
    int x, y;

    cin >> x >> y;

    v.push_back({x, y});
  }

  for(int i = 0; i < n; i++){
    cout << getRank(v, i) << " ";
  }

  return 0;
}

int getRank(vector<pair<int, int>> v, int n){
  int rank = 0, cnt = 0;

  for(int i = 0; i < v.size(); i++){
    if(n != i && v[i].first > v[n].first && v[i].second > v[n].second) cnt++;
  }

  rank = cnt + 1;

  return rank;
}