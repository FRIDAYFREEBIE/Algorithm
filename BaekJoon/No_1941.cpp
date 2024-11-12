#include <iostream>
#include <vector>
#include <queue>

using namespace std;

char arr[5][5];
bool visit[5][5];

int dirX[4] = {0, 1, 0, -1};
int dirY[4] = {-1, 0, 1, 0};

vector<pair<int, int>> selected;


int cnt;
bool isConnected() {
  queue<pair<int, int>> q;
  bool visited[5][5] = {false};
  int connectedCount = 1;

  q.push(selected[0]);
  visited[selected[0].first][selected[0].second] = true;

  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    for (int dir = 0; dir < 4; dir++) {
      int nx = current.first + dirX[dir];
      int ny = current.second + dirY[dir];

      if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;

      if (visited[nx][ny]) continue;

      for (auto &p : selected) {
        if (p.first == nx && p.second == ny) {
          visited[nx][ny] = true;
          connectedCount++;
          q.push({nx, ny});
          break;
        }
      }
    }
  }

  return connectedCount == 7;
}

void func(int x, int y, int k, int sCnt) {
  if (k == 7) {
    if (sCnt >= 4 && isConnected()) {
      cnt++;
    }
    return;
  }

  for (int i = x; i < 5; i++) {
    for (int j = (i == x ? y : 0); j < 5; j++) {
      if (!visit[i][j]) {
        visit[i][j] = true;
        selected.push_back({i, j});

        if (arr[i][j] == 'S') {
          func(i, j + 1, k + 1, sCnt + 1);
        } else {
          func(i, j + 1, k + 1, sCnt);
        }

        selected.pop_back(); 
        visit[i][j] = false;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }

  func(0, 0, 0, 0);

  cout << cnt;

  return 0;
}
