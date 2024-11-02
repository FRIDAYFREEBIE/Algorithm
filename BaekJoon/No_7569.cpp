#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int box[100][100][100]; // 토마토 상자 -1: 없음, 0: 안익음, 1: 익음
int dist[100][100][100]; // 토마토 상자 방문 0: 방문 안함

// 방문 방향
int dirX[6] = {0, 0, 1, -1, 0, 0};
int dirY[6] = {1, -1, 0, 0, 0, 0};
int dirZ[6] = {0, 0, 0, 0, 1, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int m, n, h;
  cin >> m >> n >> h;

  queue<tuple<int, int, int>> q;
  for(int i = 0; i < h; i++){ // 높이
    for(int j = 0; j < n; j++){ // 세로
      for(int k = 0; k < m; k++){ // 가로
        int temp;
        cin >> temp;
        box[i][j][k] = temp; // box[높이][세로][가로]

        if(box[i][j][k] == 1){
          q.push({i, j, k});
          dist[i][j][k] = 0;
        }
        else if(box[i][j][k] == 0){
          dist[i][j][k] = -1;
        }
      }
    }
  }

  while(!q.empty()){
    tuple<int, int, int> current = q.front(); // 현재 위치 가져오기
    q.pop();

    int curZ = get<0>(current);
    int curX = get<1>(current);
    int curY = get<2>(current);

    for(int dir = 0; dir < 6; dir++){
      int z = curZ + dirZ[dir];
      int y = curY + dirY[dir];
      int x = curX + dirX[dir];

      // 범위
      if(z < 0 || z >= h || x < 0 || x >= n || y < 0 || y >= m){
        continue;
      }

      // 방문 여부, 빈칸 여부
      if(dist[z][x][y] >= 0 || box[z][x][y] == -1){
        continue;
      }

      dist[z][x][y] = dist[curZ][curX][curY] + 1;
      q.push({z, x, y});
    }
  }

  int result = 0;
  for(int i = 0; i < h; i++){ // 높이
    for(int j = 0; j < n; j++){ // 세로
      for(int k = 0; k < m; k++){ // 가로
        if(dist[i][j][k] == -1){
          cout << -1 << "\n";
          return 0;
        }

        result = max(result, dist[i][j][k]);
      }
    }
  }

  cout << result << "\n";

  return 0;
}