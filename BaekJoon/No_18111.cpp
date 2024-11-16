#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n, m, b;
vector<vector<int>> map;

pair<int, int> calculateTime(int minHeight, int maxHeight){
  int minTime = INT_MAX, bestHeight = 0;

  for(int target = minHeight; target <= maxHeight; target++){
    int remove = 0, add = 0;

    for(int i = 0; i < n; ++i){
      for(int j = 0; j < m; ++j){
        int diff = map[i][j] - target;
        if (diff > 0) remove += diff;
        else add -= diff;
      }
    }

    if(remove + b >= add){
      int time = remove * 2 + add;
      if(time < minTime || (time == minTime && target > bestHeight)){
        minTime = time;
        bestHeight = target;
      }
    }
  }

  return {minTime, bestHeight};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> b;
  map.resize(n, vector<int>(m));

  int minHeight = 256, maxHeight = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> map[i][j];
      minHeight = min(minHeight, map[i][j]);
      maxHeight = max(maxHeight, map[i][j]);
    }
  }

  auto result = calculateTime(minHeight, maxHeight);
  cout << result.first << " " << result.second << "\n";
  return 0;
}