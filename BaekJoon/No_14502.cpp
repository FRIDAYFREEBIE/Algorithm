#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[9][9], visit[9][9], n, m, ret;;
vector<pair<int, int>> wall, virus;
const int dirX[4] = {0, 1, 0, -1};
const int dirY[4] = {-1, 0, 1, 0};

void DFS(int x, int y){
  for(int dir = 0; dir < 4; dir++){
    int nx = x + dirX[dir];
    int ny = y + dirY[dir];

    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if(visit[nx][ny] == 1) continue;
    if(arr[nx][ny] == 1) continue;

    visit[nx][ny] = 1;
    DFS(nx, ny);
  }
}

int go(){
  memset(visit, 0, sizeof(visit));
  for(auto a : virus){
    visit[a.first][a.second] = 1;

    DFS(a.first, a.second);
  }

  int cnt = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(arr[i][j] == 0 && visit[i][j] == 0) cnt++;
    }
  }

  return cnt;
}

// 1. 벽 3개 2. 바이러스 3. 안전영역 카운트
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> arr[i][j];

      if(arr[i][j] == 0) wall.push_back({i, j});
      if(arr[i][j] == 2) virus.push_back({i, j});
    }
  }

  // 1. 벽 3개
  int l = wall.size();
  for(int i = 0; i < l; i++){
    for(int j = 0; j < i; j++){
      for(int  k = 0; k < j; k++){
        arr[wall[i].first][wall[i].second] = 1;
        arr[wall[j].first][wall[j].second] = 1;
        arr[wall[k].first][wall[k].second] = 1;

        // 2. 바이러스 3. 안전영역 카운트
        ret = max(ret, go());

        arr[wall[i].first][wall[i].second] = 0;
        arr[wall[j].first][wall[j].second] = 0;
        arr[wall[k].first][wall[k].second] = 0;
      }
    }
  }

  cout << ret << "\n";

  return 0;
}