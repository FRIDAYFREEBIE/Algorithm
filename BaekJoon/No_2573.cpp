#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int ice[301][301];
int vis[301][301];
int temp[301][301];

int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
int n, m;

int count();
void update();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> ice[i][j];
    }
  }

  int year = 0;
  while(true){
    int cnt = count();

    if(cnt >= 2){
      cout << year << "\n";
      break;
    }
    else if(cnt == 0){
      cout << 0 << "\n";
      break;
    }
    
    year++;

    update();
  }

  return 0;
}

int count(){
  memset(vis, 0, sizeof(vis));
  memset(temp, 0, sizeof(temp));

  int iceCnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] != 0 || ice[i][j] == 0) {
        continue;
      }

      iceCnt++;
      queue<pair<int, int>> q;
      q.push({i, j});
      vis[i][j] = 0;

      while (!q.empty()) {
        int waterCnt = 0;
        pair<int, int> current = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];

          // 범위
          if (x < 0 || x >= n || y < 0 || y >= m) {
            continue;
          }

          // 물
          if (ice[x][y] == 0) {
            waterCnt++;
            continue;
          }

          // 방문 여부
          if (vis[x][y] != 0){
            continue;
          }

          vis[x][y] = 1;
          q.push({x, y});
        }

        temp[current.first][current.second] = waterCnt;
      }
    }
  }

  return iceCnt;
}

void update(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        if(temp[i][j] == 0){
          continue;
        }

        ice[i][j] -= temp[i][j];
        if(ice[i][j] < 0){
          ice[i][j] = 0;
        }
    }
  }
}