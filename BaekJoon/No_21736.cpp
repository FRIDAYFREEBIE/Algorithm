#include <iostream>
#include <queue>

using namespace std;

int n, m;
char campus[601][601];
bool visit[601][601];
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> campus[i][j];

      if(campus[i][j] == 'I'){
        q.push({i, j});
        visit[q.front().first][q.front().second] = true;
      }
    }
  }


  int friendCnt = 0;
  while(!q.empty()){
    pair<int ,int> current = q.front();
    q.pop();

    for(int dir = 0; dir < 4; dir++){
      int x = current.first + dirX[dir];
      int y = current.second + dirY[dir];

      // 범위
      if(x < 0 || x >= n || y < 0 || y >= m) continue;
      
      // 방문 여부, 벽 여부
      if(visit[x][y] || campus[x][y] == 'X') continue;

      // 사람 여부
      if(campus[x][y] == 'P') friendCnt++;

      visit[x][y] = true;
      q.push({x, y});
    }
  }

  if(friendCnt == 0) cout << "TT" << "\n";
  else cout << friendCnt << "\n";

  return 0;
}