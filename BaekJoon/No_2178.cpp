#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int board[100][100];

  // 방문 방향
  int dirX[4] = {1, 0, -1, 0};
  int dirY[4] = {0, 1, 0, -1};

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string line;
    cin >> line;

    for (int j = 0; j < m; j++) {
      board[i][j] = line[j] - '0';
    }
  }

  queue<pair<int, int>> q; // BFS
  int distance[100][100]; // 거리 표시 (-1: 방문 안함)

  fill(&distance[0][0], &distance[0][0] + 100 * 100, -1);

  // 첫 번째
  distance[0][0] = 0;
  q.push({0, 0});

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      // 범위를 벗어났다면
      if(x < 0 || x >= n || y < 0 || y >= m){
        continue;
      }

      // 이미 방문 했거나 길이 아니라면
      if(distance[x][y] != -1 || board[x][y] == 0){
        continue;
      }

      distance[x][y] = distance[current.first][current.second] + 1;
      q.push({x, y});
    }
  }

  cout << distance[n - 1][m - 1] + 1 << "\n";

  return 0;
}