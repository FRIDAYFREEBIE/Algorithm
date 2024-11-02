#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char tower[1000][1000];
int jihunDist[1000][1000]; // 0: X
int fireDist[1000][1000]; // 0: X

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  for(int i = 0; i < t; i++){
    int w, h;
    cin >> w >> h;

    for (int a = 0; a < h; a++){
      fill(fireDist[a], fireDist[a] + w, -1);
      fill(jihunDist[a], jihunDist[a] + w, -1);
    }

    pair<int, int> jihunPos;
    queue<pair<int, int>> fireQueue;

    for(int j = 0; j < h; j++){
      for(int k = 0; k < w; k++){
        cin >> tower[j][k];

        // 지훈의 위치
        if(tower[j][k] == '@'){
          jihunPos = {j, k};
        }

        // 불의 위치
        if(tower[j][k] == '*'){
          fireQueue.push({j, k});
          fireDist[j][k] = 0;
        }
      }
    }

    if(jihunPos.first == 0 || jihunPos.first == h - 1 || jihunPos.second == 0 || jihunPos.second == w - 1){
      cout << "1" << "\n";
      continue;
    }

    // 불 BFS
    while(!fireQueue.empty()){
      pair<int, int> current = fireQueue.front();
      fireQueue.pop();

      for(int dir = 0; dir < 4; dir++){
        int x = current.first + dirX[dir];
        int y = current.second + dirY[dir];

        // 범위
        if(x < 0 || x >= h || y < 0|| y >= w){
          continue;
        }

        // 방문 여부, 벽 여부
        if(fireDist[x][y] != -1 || tower[x][y] == '#'){
          continue;
        }

        fireDist[x][y] = fireDist[current.first][current.second] + 1;
        fireQueue.push({x, y});
      }
    }

    // 지훈이 BFS
    queue<pair<int, int>> jihunQueue;
    jihunQueue.push(jihunPos);
    jihunDist[jihunPos.first][jihunPos.second] = 0;
    bool escaped = false;

    while(!jihunQueue.empty() && !escaped){
      pair<int,int> current = jihunQueue.front();
      jihunQueue.pop();

      for(int dir = 0; dir < 4; dir++){
        int x = current.first + dirX[dir];
        int y = current.second + dirY[dir];

        // 범위
        if(x < 0 || x >= h || y < 0|| y >= w){
          cout << jihunDist[current.first][current.second] + 1 << "\n";
          escaped = true;
          break;
        }

        // 방문 여부, 벽 여부
        if(jihunDist[x][y] != -1 || tower[x][y] == '#'){
          continue;
        }

        // 불 여부
        if (fireDist[x][y] != -1 && fireDist[x][y] <= jihunDist[current.first][current.second] + 1) {
          continue;
        }

        jihunDist[x][y] = jihunDist[current.first][current.second] + 1;
        jihunQueue.push({x, y});
      }
    }

    if(!escaped){
      cout << "IMPOSSIBLE" << "\n";
    }
  }

  return 0;
}