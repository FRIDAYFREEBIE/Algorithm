#include <iostream>
#include <queue>

using namespace std;

int n, w, l, ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> w >> l;

  queue<int> truck;
  for(int i = 0; i < n; i++){
    int temp;
    cin >> temp;

    truck.push(temp);
  }

  queue<pair<int, int>> bridge; // 트럭 하중, 이동 한 거리

  cout << ans << "\n";

  return 0;
}