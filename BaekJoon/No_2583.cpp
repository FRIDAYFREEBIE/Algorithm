#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int board[101][101];
int vis[102][102];

// 방문 방향
int dirX[4] = {1, 0, -1, 0};
int dirY[4] = {0, 1, 0, -1};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int m, n, k;
  cin >> m >> n >> k;

  while(k--){
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for (int j = y1; j < y2; j++){
      for (int k = x1; k < x2; k++){
        board[j][k] = 1;
      }
    }
  }

  vector<int> result;
  int cnt = 0;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(board[i][j] == 1 || vis[i][j] == 1){
        continue;
      }

      queue<pair<int, int>> q;
      vis[i][j] = 1;
      q.push({i, j});
      cnt++;

      int size = 1;
      while(!q.empty()){
        pair<int, int> current = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++){
          int x = current.first + dirX[dir];
          int y = current.second + dirY[dir];

          // 범위
          if(x < 0 || x >= m || y < 0 || y >= n){
            continue;
          }

          // 집, 방문
          if(board[x][y] == 1 || vis[x][y] == 1){
            continue;
          }

          q.push({x, y});
          vis[x][y] = 1;
          size++;
        }
      }
      result.push_back(size);
    }
  }
  
  sort(result.begin(), result.end());

  cout << cnt << "\n";
  for(int a : result){
    cout << a << " ";
  }

  return 0;
}