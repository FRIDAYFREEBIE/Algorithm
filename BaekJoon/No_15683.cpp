#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[9][9];
int temp[9][9];
vector<pair<int, int>> cctv;

int n, m, minSpot = 100;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void fillTemp(int x, int y, int dir) {
  while (true) {
    x += dx[dir];
    y += dy[dir];

    if (x < 0 || x >= n || y < 0 || y >= m) break;
    if (arr[x][y] == 6) break;
    if (temp[x][y] == 0) temp[x][y] = -1;
  }
}

int countSpot() {
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (temp[i][j] == 0) count++;
    }
  }

  return count;
}

void func(size_t index) {
    if (index == cctv.size()) {
      minSpot = min(minSpot, countSpot());
      return;
    }

    int x = cctv[index].first;
    int y = cctv[index].second;
    int cctvType = arr[x][y];

    int backup[9][9];
    memcpy(backup, temp, sizeof(temp));

    if (cctvType == 1) {
      for (int i = 0; i < 4; i++) {
        fillTemp(x, y, i);
        func(index + 1);
        memcpy(temp, backup, sizeof(temp));
      }
    }
    else if (cctvType == 2) {
      for (int i = 0; i < 2; i++) {
        fillTemp(x, y, i);
        fillTemp(x, y, i + 2);
        func(index + 1);
        memcpy(temp, backup, sizeof(temp));
      }
    }
    else if (cctvType == 3) {
      for (int i = 0; i < 4; i++) {
        fillTemp(x, y, i);
        fillTemp(x, y, (i + 1) % 4);
        func(index + 1);
        memcpy(temp, backup, sizeof(temp));
      }
    }
    else if (cctvType == 4) {
      for (int i = 0; i < 4; i++) {
        fillTemp(x, y, i);
        fillTemp(x, y, (i + 1) % 4);
        fillTemp(x, y, (i + 2) % 4);
        func(index + 1);
        memcpy(temp, backup, sizeof(temp));
      }
    }
    else if (cctvType == 5) {
      for (int i = 0; i < 4; i++) {
        fillTemp(x, y, i);
      }

      func(index + 1);
      memcpy(temp, backup, sizeof(temp));
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] != 0 && arr[i][j] != 6) cctv.push_back({i, j});
    }
  }

  memcpy(temp, arr, sizeof(arr));
  func(0);

  cout << minSpot << "\n";
  return 0;
}
