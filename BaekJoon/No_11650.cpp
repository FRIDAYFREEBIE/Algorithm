#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);

  int n;

  // 2차원 벡터
  vector<pair<int, int>> v;

  cin >> n;

  // 벡터 입력
  for(int i = 0; i < n; i++){
    int x, y;

    cin >> x  >> y;

    v.push_back({x, y});
  }

  // 벡터 정렬
  sort(v.begin(), v.end());

  // 순회
  for(const auto& p : v){
    cout << p.first << " " << p.second << "\n";
  }

  return 0;
}