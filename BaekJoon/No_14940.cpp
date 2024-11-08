#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int map[1001][1001];
int dist[1001][1001];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  memset(dist, -1, sizeof(dist));

  int n, m;
  cin >> n >> m;

  pair<int, int> startPos;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> map[i][j];

      if(map[i][j] == 2){
        startPos = {i, j};
      }
      else if(map[i][j] == 0){
        dist[i][j] = 0;
      }
    }
  }

  queue<pair<int, int>> q;
  q.push(startPos);
  dist[startPos.first][startPos.second] = 0;

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      // 범위
      if(x < 0 || x >= n || y < 0 || y >= m){
        continue;
      }

      // 방문 여부
      if(dist[x][y] != -1){
        continue;
      }

      dist[x][y] = dist[current.first][current.second] + 1;
      q.push({x, y});
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cout << dist[i][j] << " ";
    }
    
    cout << "\n";
  }

  return 0;
}