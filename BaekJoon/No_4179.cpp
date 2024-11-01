#include <iostream>
#include <queue>
#include <vector>

using namespace std;

string maze[1000]; // 미로

// 거리 -1: 방문 X
int fireDist[1000][1000];
int jihunDist[1000][1000];

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  // -1로 초기화
  for (int i = 0; i < 1000; i++){
    fill(fireDist[i], fireDist[i] + 1000, -1);
    fill(jihunDist[i], jihunDist[i] + 1000, -1);
  }

  int r, c;
  cin >> r >> c;

  vector<pair<int, int>> fires; // 불 위치
  pair<int, int> jihun; // 지훈

  for(int i = 0; i < r; i++){
    cin >> maze[i];
    for(int j = 0; j < c; j++){
      char ch = maze[i][j];
      if(ch == 'F'){
        fires.push_back({i, j});
      }
      else if(ch == 'J'){
        jihun = {i, j};
      }
    }
  }

  // 불 BFS
  queue<pair<int, int>> fireQueue;
  for(auto fire : fires){
    fireQueue.push(fire);
    fireDist[fire.first][fire.second] = 0;
  }

  while(!fireQueue.empty()){
    pair<int, int> current = fireQueue.front();
    fireQueue.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      if(x < 0 || x >= r || y < 0 || y >= c){
        continue;
      }

      if(fireDist[x][y] != -1 || maze[x][y] == '#'){
        continue;
      }

      fireDist[x][y] = fireDist[current.first][current.second] + 1;
      fireQueue.push({x, y});
    }
  }

  // 지훈 BFS
  queue<pair<int, int>> jihunQueue;
  jihunQueue.push(jihun);
  jihunDist[jihun.first][jihun.second] = 0;

  while(!jihunQueue.empty()){
    pair<int, int> current = jihunQueue.front();
    jihunQueue.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      // 범위 밖 = 탈출
      if(x < 0 || x >= r || y < 0 || y >= c){
        cout << jihunDist[current.first][current.second] + 1 << "\n";
        return 0;
      }

      // 방문하지 않음, 불 보다 빠를 때
      if(jihunDist[x][y] == -1 && (fireDist[x][y] == -1 || jihunDist[current.first][current.second] + 1 < fireDist[x][y]) && maze[x][y] != '#'){
        jihunDist[x][y] = jihunDist[current.first][current.second] + 1;
        jihunQueue.push({x, y});
      }
    }
  }

  cout << "IMPOSSIBLE" << "\n";
  return 0;
}
