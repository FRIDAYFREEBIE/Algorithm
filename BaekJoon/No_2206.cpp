#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int map[1000][1000];
int visit[1000][1000][2]; // [x][y][벽]

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char temp;
      cin >> temp;
      map[i][j] = temp - '0';
    }
  }

  visit[0][0][0] = 1;
  queue<tuple<int, int, int>> q; // <x, y, 벽>
  q.push({0, 0, 0});

  while (!q.empty()) {
    tuple<int, int, int> current = q.front();
    q.pop();

    int curX = get<0>(current);
    int curY = get<1>(current);
    int wall = get<2>(current);

    if (curX == n - 1 && curY == m - 1) {
      cout << visit[curX][curY][wall] << "\n";
      return 0;
    }

    for (int dir = 0; dir < 4; dir++) {
      int x = curX + dirX[dir];
      int y = curY + dirY[dir];

      // 범위 체크
      if (x < 0 || x >= n || y < 0 || y >= m) {
        continue;
      }

      // 벽이 아닌 경우
      if (map[x][y] == 0 && visit[x][y][wall] == 0) {
        visit[x][y][wall] = visit[curX][curY][wall] + 1;
        q.push({x, y, wall});
      }

      // 벽인데 아직 부술 수 있는 경우
      if (map[x][y] == 1 && wall == 0 && visit[x][y][1] == 0) {
        visit[x][y][1] = visit[curX][curY][wall] + 1;
        q.push({x, y, 1});
      }
    }
  }

  cout << -1 << "\n";
  
  return 0;
}
