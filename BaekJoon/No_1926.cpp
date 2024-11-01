#include <iostream>
#include <queue>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int board[500][500]; // 그림 보드
  int visit[500][500] = {0}; // 방문한 보드

  // 방문 방향
  int dirX[4] = {1, 0, -1, 0};
  int dirY[4] = {0, 1, 0, -1};

  int n, m;
  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> board[i][j];
    }
  }

  int pictureCnt = 0; // 그림 갯수
  int maxPictureSize = 0; // 가장 큰 그림 크기
  queue<pair<int, int>> q; // BFS <행, 열>

  // 가로 세로 모든 칸을 탐색
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      // 그림이 아니라면
      if(board[i][j] == 0 || visit[i][j]){
        continue;
      }

      // 방문 표시
      visit[i][j]= 1;
      q.push({i, j});
      pictureCnt++;

      int pictureSize = 0;
      while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        pictureSize++;

        for(int dir = 0; dir < 4; dir++){
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];
          
          // 범위를 벗어났다면
          if(x < 0 || x >= n || y < 0 || y >= m){
            continue;
          }

          // 이미 방문 했거나 그림이 아니라면
          if(visit[x][y] || board[x][y] == 0){
            continue;
          }
          
          visit[x][y] = 1; // 방문 표시
          q.push({x, y});
        }
      }

      if(maxPictureSize < pictureSize){
        maxPictureSize = pictureSize;
      }
    }
  }

  cout << pictureCnt << "\n" << maxPictureSize << "\n";

  return 0;
}