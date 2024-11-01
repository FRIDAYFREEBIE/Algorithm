#include <iostream>
#include <queue>

using namespace std;

int dist[1000][1000]; // 거리 -1: 방문 안함
int board[1000][1000]; // 토마토 상자 -1: 없음 0: 안익음 1: 익음

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n, m;
  cin >> m >> n;

  queue<pair<int, int>> q; // BFS

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
      if(board[i][j] == 1){
        q.push({i, j});
        dist[i][j] = 0;
      }
      else if(board[i][j] == 0){
        dist[i][j] = -1;
      }
    }
  }

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

      // 토마토가 없거나 이미 방문했다면
      if(board[x][y] == -1 || dist[x][y] >= 0){
        continue;
      }

      dist[x][y] = dist[current.first][current.second] + 1;
      q.push({x, y});
    }
  }

  int result = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(dist[i][j] == -1){
        cout << -1 << "\n";
        return 0;
      }

      if(result < dist[i][j]){
        result = dist[i][j];
      }
    }

  }

  cout << result << "\n";

  return 0;
}