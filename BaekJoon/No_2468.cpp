#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int area[101][101];
int visit[101][101];
int dirX[] = {0, 1, 0, -1};
int dirY[] = {1, 0, -1, 0};

void bfs(int i, int j, int limit);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  int maxHeight = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> area[i][j];
      maxHeight = max(maxHeight, area[i][j]);
    }
  }

  int maxCnt = 0;
  for(int limit = 0; limit <= maxHeight; limit++){
    for(int i = 0; i < n; i++) {
      fill(visit[i], visit[i] + n, 0);
    }

    int cnt = 0;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        if(area[i][j] > limit && visit[i][j] == 0){
          bfs(i, j, limit);
          cnt++;
        }
      }
    }
    maxCnt = max(maxCnt, cnt);
  }

  cout << maxCnt << "\n";
  return 0;
}

void bfs(int i, int j, int limit){
  queue<pair<int, int>> q;
  visit[i][j] = 1;
  q.push({i, j});

  while(!q.empty()){
    pair<int, int> current = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      if(x >= 0 && x < n && y >= 0 && y < n){
        if(visit[x][y] == 0 && area[x][y] > limit){
          visit[x][y] = 1;
          q.push({x, y});
        }
      }
    }
  }
}
